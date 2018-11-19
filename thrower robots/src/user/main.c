#include "rcc.h"
#include "ticks.h"
#include "gpio.h"
#include "leds.h"
#include "buttons.h"
#include "buzzer.h"
#include "uart.h"
#include "lcd_main.h"
#include "oled.h"
#include "camera.h"
#include "pwm.h"
#include "adc.h"
#include "main.h"
#include "lineTracker.h"

const int AUTORELOAD=6000;

const int TURNINGTIME=1000;

//coordinate structure
typedef struct
{
	int x;
	int y;
} Coordinate;

//not useful for now 
typedef enum {FORWARD=1,BACKWARD=-1,LEFT=2,RIGHT=3}Direction;

typedef enum {LEFTWHEEL,RIGHTWHEEL}Wheel;

void ManualMove(Direction);

const int SPEED=6000/5;
int LeftCurrentPower=SPEED;
int RightCurrentPower=SPEED;


//direction
typedef enum 
{
    EAST=0,
    WEST=180,
    NORTH=90,
    SOUTH=270,
    CLKWISE,
    ANTICLKWISE,
    RACKPICK,//piston action
    RACKDROP,
    SHUFFLEGRAB,
    SHUFFLERELEASE,
	SHOOT,
	UNSHOOT
}Actions;

//a set of robot action, will go from start zone to throwing zone
Actions RobotActions[]=
		{		WEST,WEST,WEST,WEST,EAST,
				CLKWISE,
				NORTH,NORTH,NORTH,NORTH,NORTH,
				CLKWISE,
				EAST,EAST,EAST,EAST
		};

		//size of action array
int Actions_Length=sizeof(RobotActions)/sizeof(RobotActions[0]);
		
		//coordinate of the robot
Coordinate CurrentPosition;
		
//debounce variable to prevent mutiple access
int LT1_state = 0;
int LT2_state=0;



void Usart3_Send_Data(char *string)
{
    while(*string)
    {
        /* ????? USART1 */
        USART_SendData(USART3, (unsigned short int) *string++);
 
        /* ???????? */
        while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
    }
}




void ManualMove(Direction dir)
{
    int this_ticks =0;
    int Current=this_ticks;

    switch(dir)
    {
        case FORWARD: motor_control(MOTOR1,SPEED,dir); motor_control(MOTOR2,SPEED,dir);break;
        case BACKWARD: motor_control(MOTOR1,SPEED,dir); motor_control(MOTOR2,SPEED,dir);break;
        case LEFT: motor_control(MOTOR1,LeftCurrentPower,-1*dir); motor_control(MOTOR2,RightCurrentPower,dir);break;
        case RIGHT: motor_control(MOTOR1,LeftCurrentPower,dir); motor_control(MOTOR2,RightCurrentPower,-1*dir);break;
        default:break;
    }

    while(1)
    {
			int i=0;
			led_on(LED1);
       for (;i<720000;i++){;}
			led_off(LED1);

            motor_control(MOTOR1,1,1);
            motor_control(MOTOR2,1,1);
            return;
      
    }   
}

void AddPower(Wheel wheel)
{
    switch(wheel)
    {
        case LEFTWHEEL:
        if(LeftCurrentPower+SPEED<=AUTORELOAD)
        {LeftCurrentPower+=SPEED;}
        break;
        case RIGHTWHEEL:
        if(RightCurrentPower+SPEED<=AUTORELOAD)
        {RightCurrentPower+=SPEED;}
        break;
    }
}


void MinusPower(Wheel wheel)
{
    switch(wheel)
    {
        case LEFTWHEEL:
        if(LeftCurrentPower-SPEED>=1)
        {LeftCurrentPower-=SPEED;}
        break;
        case RIGHTWHEEL:
        if(RightCurrentPower-SPEED>=1)
        {RightCurrentPower-=SPEED;}
        break;
    }
}



// Move east until it sees a white line and then stop
void Move(Actions Compus,int dir)
{
	//start moving
	motor_control(MOTOR1,SPEED,dir);
	motor_control(MOTOR2,SPEED,dir);
	int this_ticks = get_ticks();

	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		//debouncing condition
		if(LT1_state==1&&ReadLineTracker(lineTracker1)==0)
		{
			LT1_state=0;
		}


		//Stop when It read white lines
		if(ReadLineTracker(lineTracker1)==1&&LT1_state==0)
		{
			LT1_state=1;
			motor_control(MOTOR1,1,dir);
			motor_control(MOTOR2,1,dir);
			//update the robots coordinate
            switch(Compus)
            {
                case EAST:CurrentPosition.x++;break;
				case WEST:CurrentPosition.x--;break;
				case NORTH:CurrentPosition.y--;break;
				case SOUTH:CurrentPosition.y++;break;
                default:break;
            }
				
			return;
		}
	}
}




void TurnClockWise()
{
	
	motor_control(MOTOR1,SPEED,1);
	motor_control(MOTOR2,SPEED,-1);
	int this_ticks = get_ticks();

	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		if(LT1_state==1&&ReadLineTracker(lineTracker1)==0)
		{
			LT1_state=0;
		}
		//Stop when It read white lines
		if(ReadLineTracker(lineTracker1)==1&&LT1_state==0)
		{
	    	LT1_state=1;
			motor_control(MOTOR1,1,1);
		    motor_control(MOTOR2,1,1);
			return;					
		}
	}
}

//return absolute value of a number
int abs(int num)
{
	if(num<0){num*=-1;}
	
	return num;
}


void ManualMode()
{
    while(1)
    {
        ;   
    }
}




void AutoModeThrower()
{
	//initialize current position=5,5 coordinate
	CurrentPosition.x=5;
	CurrentPosition.y=5;
	
  //init enter once only
	int init=1;
	
	//initial direction is west
	Actions direction=WEST;
	int this_ticks =get_ticks();
	//int last_led_ticks=get_ticks();

	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		int dir=1;
		
		//only enter once for getting the car to start
		//ideally will go to the throwing zone
		if(init==1)
		{
			for(int i=0;i<Actions_Length;i++)
			{
				switch(RobotActions[i])
				{
					case EAST:Move(EAST,abs(RobotActions[i]-direction)==180?dir*=-1:dir);direction=EAST;break;
					case WEST:Move(WEST,abs(RobotActions[i]-direction)==180?dir*=-1:dir);direction=WEST;break;
					case NORTH:Move(NORTH,abs(RobotActions[i]-direction)==180?dir*=-1:dir);direction=NORTH;break;
					case SOUTH:Move(SOUTH,abs(RobotActions[i]-direction)==180?dir*=-1:dir);direction=SOUTH;break;
					case CLKWISE:TurnClockWise();break;
					default:break;
				}
				//delay 2s to hold the car
				delay(3000);			
			}
			init=2;
		}
        break;
	}
}


void UARTOnReceiveHandler(const u8 received){
	
     switch((char)received)
     {
         case 'w':led_on(LED2); uart_tx_str(COM3,"forward\n");ManualMove(FORWARD);break;
         case 'a':led_off(LED2);ManualMove(LEFT);uart_tx_str(COM3,"left \n");break;
         case 's':ManualMove(BACKWARD);uart_tx_str(COM3,"back \n");break;
         case 'd':ManualMove(RIGHT);uart_tx_str(COM3,"right\n");break;
         case 'l':AddPower(LEFTWHEEL);uart_tx_str(COM3,"add left power\n");break;
         case 'x':MinusPower(LEFTWHEEL);uart_tx_str(COM3,"sub left power\n");break;
         case 'r':AddPower(RIGHTWHEEL);uart_tx_str(COM3,"add right power\n");break;
         case 'y':MinusPower(RIGHTWHEEL);uart_tx_str(COM3,"sub right power\n");break;
				 default:uart_tx_str(COM3,"invalid action\n"); break;
     }
    return;
}


int main()
{
	rcc_init();
	//gpio_rcc_init(GPIOA);
    ticks_init();  
	leds_init();
	buttons_init();
    tft_init(1, BLACK, WHITE, RED, YELLOW);
    uart_init(COM3, 9600);
	  uart_rx_init(COM3,&UARTOnReceiveHandler);
	  
	
	
	//initialize motor, prescalar 10, autoreload=6000
	motor_init(MOTOR1, 39, AUTORELOAD,1,1);
	motor_init(MOTOR2, 39, AUTORELOAD,1,1);
	uint32_t lastticks=get_ticks();
	//initialize linetracker
	lineTracker_init();
     
	//enter thrower robot movement subroutine
	while(1)
    {
	    if(button_pressed(BUTTON1))
	    {
				led_on(LED1);
	    	break;
	    }
    }

		AutoModeThrower();
    ManualMode();
	return 0;
}
