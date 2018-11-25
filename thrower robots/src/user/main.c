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
#include "Ultrasonar.h"
#include "Piston.h"

const int AUTORELOAD=6000;

const int TURNINGTIME=1000;

const int MOVEMENTTIME=2000;

const int PICKRACKDISTANCE=100;

char ReceivedAction='\0';

int CanEnterManual=0;

//coordinate structure
typedef struct
{
	int x;
	int y;
} Coordinate;

//not useful for now 
typedef enum {FORWARD=1,BACKWARD=0,LEFT=2,RIGHT=3}Direction;

typedef enum {LEFTWHEEL,RIGHTWHEEL}Wheel;

void ManualMove(Direction);

const int LEFTSPEED=200;

const int RIGHTSPEED=100;

int LeftCurrentPower=LEFTSPEED;

int RightCurrentPower=RIGHTSPEED;


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
		{		
			WEST,WEST,WEST,WEST,RACKPICK,EAST,
			CLKWISE,
			NORTH,NORTH,NORTH,NORTH,NORTH,
			CLKWISE,
			EAST,EAST,EAST,EAST,RACKDROP
		};

		//size of action array
int Actions_Length=sizeof(RobotActions)/sizeof(RobotActions[0]);
		
		//coordinate of the robot
Coordinate CurrentPosition;
		
//debounce variable to prevent mutiple access
int LT1_state = 0;
int LT2_state=0;


void ManualMove(Direction dir)
{
    int this_ticks =get_ticks();
    int Current=this_ticks;

    switch(dir)
    {
        case FORWARD: motor_control(MOTOR1,LEFTSPEED,dir); motor_control(MOTOR2,RIGHTSPEED,dir);break;
        case BACKWARD: motor_control(MOTOR1,LEFTSPEED,dir); motor_control(MOTOR2,RIGHTSPEED,dir);break;
        case LEFT: motor_control(MOTOR1,LeftCurrentPower,0*dir); motor_control(MOTOR2,RightCurrentPower,dir);break;
        case RIGHT: motor_control(MOTOR1,LeftCurrentPower,dir); motor_control(MOTOR2,RightCurrentPower,0*dir);break;
        default:break;
    }
		
		
		delay(1000);
		motor_control(MOTOR1,0,dir); motor_control(MOTOR2,0,dir);
		
//    while(1)
//    {
//		while (get_ticks() == this_ticks);
//		this_ticks = get_ticks();

//		if(this_ticks-Current>=MOVEMENTTIME)
//		{
//					motor_control(MOTOR1,1,1);
//       	 	motor_control(MOTOR2,1,1);
//         	return;
//		}

//       
//      
//    }   
}

void AddPower(Wheel wheel)
{
    switch(wheel)
    {
        case LEFTWHEEL:
        if(LeftCurrentPower+LEFTSPEED<=AUTORELOAD)
        {LeftCurrentPower+=LEFTSPEED;}
        break;
        case RIGHTWHEEL:
        if(RightCurrentPower+RIGHTSPEED<=AUTORELOAD)
        {RightCurrentPower+=RIGHTSPEED;}
        break;
    }
}


void MinusPower(Wheel wheel)
{
    switch(wheel)
    {
        case LEFTWHEEL:
        if(LeftCurrentPower-LEFTSPEED>=1)
        {LeftCurrentPower-=LEFTSPEED;}
        break;
        case RIGHTWHEEL:
        if(RightCurrentPower-RIGHTSPEED>=1)
        {RightCurrentPower-=RIGHTSPEED;}
        break;
    }
}


void GoStraightAjustment(){

     motor_control(MOTOR1,1,1);
		servo_control(SERVO1, 1);
		motor_control(MOTOR2,1,0);
		servo_control(SERVO3, 1);
     delay(50);
     LT1_state=ReadLineTracker(lineTracker1);
     LT2_state=ReadLineTracker(lineTracker2);
    while(!(LT1_state&&LT2_state))
    {
				if(LT1_state==1&&LT2_state==0)
        {
            //rotate anti-clockwise
					servo_control(SERVO1, LEFTSPEED);
            motor_control(MOTOR1,LEFTSPEED,1);
					servo_control(SERVO3, RIGHTSPEED);
						motor_control(MOTOR2,RIGHTSPEED,0);
            delay(100);
        }
        else if(LT2_state==1&&LT1_state==0)
        {
	        //rotate clockwise
					servo_control(SERVO1, LEFTSPEED);
            motor_control(MOTOR1,LEFTSPEED,1);
					servo_control(SERVO3, RIGHTSPEED);
	        motor_control(MOTOR2,RIGHTSPEED,0);
            delay(100);
        }
        while(ReadLineTracker(lineTracker1)+ReadLineTracker(lineTracker2)<1)
        {
					servo_control(SERVO1, LEFTSPEED);
          motor_control(MOTOR1,LEFTSPEED,1);
					servo_control(SERVO3, RIGHTSPEED);
	        motor_control(MOTOR2,RIGHTSPEED,1);
        }
				servo_control(SERVO1, 1);
        motor_control(MOTOR1,1,1);
				servo_control(SERVO3, 1);
				motor_control(MOTOR2,1,1);
        delay(50);
    }
	
}

// Move east until it sees a white line and then stop
void Move(Actions Compus,int dir)
{
	//start moving
	if(dir<0){dir=0;}
	
	servo_control(SERVO1, LEFTSPEED);
	motor_control(MOTOR1,LEFTSPEED,dir);
	servo_control(SERVO3, RIGHTSPEED);
	motor_control(MOTOR2,RIGHTSPEED,dir);
	int this_ticks = get_ticks();

	while (1)
	{
		if(button_pressed(BUTTON1))
		{
			servo_control(SERVO1, 1);
			motor_control(MOTOR1,1,dir);
			servo_control(SERVO3, 1);
			motor_control(MOTOR2,1,dir);
		CurrentPosition.x++;CurrentPosition.y++;break;
		}
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		//debouncing condition
		if(LT1_state==1&&ReadLineTracker(lineTracker1)==0)
		{
			LT1_state=0;
		}
		
		if(LT2_state==1&&ReadLineTracker(lineTracker2)==0)
		{
			LT2_state=0;
		}

		//Stop when It read white lines
		if((ReadLineTracker(lineTracker1)==1&&LT1_state==0)||(ReadLineTracker(lineTracker2)==1&&LT2_state==0))
		{
			if(ReadLineTracker(lineTracker1)==1&&LT1_state==0)
			{LT1_state=1;}
			if(ReadLineTracker(lineTracker2)==1&&LT2_state==0)
			{LT2_state=1;}
			
			GoStraightAjustment();
			servo_control(SERVO1, 1);
			motor_control(MOTOR1,1,dir);
			servo_control(SERVO3, 1);
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


void PostTurnAdjustment(){
    int LT1_temp = 0;
		int LT2_temp = 0;
		while(!(LT1_temp&&LT2_temp)){

		if(LT1_temp){
			motor_control(MOTOR1,LEFTSPEED,0);
			servo_control(SERVO1, LEFTSPEED);
			motor_control(MOTOR2,RIGHTSPEED,1);
			servo_control(SERVO3, RIGHTSPEED);
		}
		else{			
			servo_control(SERVO1, LEFTSPEED);
			motor_control(MOTOR1,LEFTSPEED,1);
			servo_control(SERVO3,RIGHTSPEED);
			motor_control(MOTOR2,RIGHTSPEED,0);
		}
		delay(100);
		servo_control(SERVO1, LEFTSPEED);
		motor_control(MOTOR1,LEFTSPEED,1);
		servo_control(SERVO3,RIGHTSPEED);
		motor_control(MOTOR2,RIGHTSPEED,1);
		while(LT1_temp+LT2_temp < 1)
		{
			LT1_temp = ReadLineTracker(lineTracker1);
			LT2_temp = ReadLineTracker(lineTracker2);
		}
	}
}

//prerequisite: both sensors detect line
void TurnClockWise()
{
	
	motor_control(MOTOR1,LEFTSPEED,1);
	servo_control(SERVO1, LEFTSPEED);
	motor_control(MOTOR2,1,0);
	servo_control(SERVO3, 1);
	int this_ticks = get_ticks();

	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		if(LT1_state==1&&ReadLineTracker(lineTracker1)==0)
		{
			LT1_state=0;
		}
		if(LT2_state==1&&ReadLineTracker(lineTracker2)==0)
		{
			LT2_state=0;
		}
		//When LT2=1 , then adjust
		if(ReadLineTracker(lineTracker2)==1&&LT2_state==0)
		{
			while(!(ReadLineTracker(lineTracker1)&&ReadLineTracker(lineTracker2)))
      {
				PostTurnAdjustment();
			}
	      LT1_state = 1;
				LT2_state = 1;			
				servo_control(SERVO1, 1);
				servo_control(SERVO3, 1);
				motor_control(MOTOR1,1,1);
		    motor_control(MOTOR2,1,1);			
				break;
		}
	
	}
}

//return absolute value of a number
int abs(int num)
{
	if(num<0){num*=-1;}
	
	return num;
}

void GrabSpecialShuttlecock()
{
	Push_Piston(Grabber);
}



void ManualMode()
{	
	
		int dir=0;
		int this_ticks =get_ticks();
    while(1)
    {
 		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

			
			//pc6=pwm1
			//pc7=pwm2
			//pa8=dir2
			//pc3=dir1
    	switch((char)ReceivedAction)
     {
	case 'm': gpio_init(&PC7,GPIO_Mode_Out_PP);
	gpio_init(&PA8,GPIO_Mode_Out_PP);
	
	//motor1
	gpio_init(&PC6,GPIO_Mode_Out_PP);
	gpio_init(&PC3,GPIO_Mode_Out_PP);
			 gpio_reset(&PC6);gpio_reset(&PC7);
			 gpio_set(&PA8);gpio_set(&PC3);
			 ReceivedAction='\0';uart_tx_str(COM3,"inited");break;
			 case 'w':gpio_reset(&PC6);gpio_reset(&PC7);led_on(LED2);gpio_set(&PA8);gpio_set(&PC3);ReceivedAction='\0';
		 uart_tx_str(COM3,"move forward");break;
       case 's':gpio_reset(&PC6);gpio_reset(&PC7);gpio_reset(&PA8);gpio_reset(&PC3);ReceivedAction='\0';
		 uart_tx_str(COM3,"backward");break;
				case 'a':gpio_reset(&PC6);gpio_reset(&PC7);gpio_set(&PA8);gpio_reset(&PC3);ReceivedAction='\0';
		 uart_tx_str(COM3,"left");break;
				 case 'd':gpio_reset(&PC6);gpio_reset(&PC7);gpio_reset(&PA8);gpio_set(&PC3);ReceivedAction='\0';
		 uart_tx_str(COM3,"right");break;
			 
				 case 't':gpio_set(&PC6);gpio_set(&PC7);ReceivedAction='\0';
		 uart_tx_str(COM3,"stop");break;
			 
				 case 'x':Push_Piston(Thrower);ReceivedAction='\0';
		 uart_tx_str(COM3,"throw");break;
			 
				 case 'y':Pull_Piston(Thrower);ReceivedAction='\0';
		 uart_tx_str(COM3,"pull back");break;
		 
				 case 'o':Push_Piston(Grabber);ReceivedAction='\0';
		 uart_tx_str(COM3,"grabber push");break;
		 
		  case 'p':Pull_Piston(Grabber);ReceivedAction='\0';
		 uart_tx_str(COM3,"grabber pull");break;
			 
				 default: 
		 
		 if(ReceivedAction!='\0')
		 {
			 uart_tx_str(COM3,"invalid action\n");
			 ReceivedAction='\0';
		 }
		 break;
     }

		delay(100);gpio_set(&PC6);gpio_set(&PC7);		 
    } 
}


void PickRack()
{
	int this_ticks =get_ticks();
	int nowticks=this_ticks;
	while(1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		if(this_ticks-nowticks>=25)
		{
			motor_control(MOTOR1,1,1);
			motor_control(MOTOR2,1,1);
			sonar_start();
			nowticks=this_ticks;
		}

		if(sonar_get()<=PICKRACKDISTANCE)
		{
			Push_Piston(Grabber);
			break;
		}

		delay(50);
		motor_control(MOTOR1,LEFTSPEED,1);
		motor_control(MOTOR2,RIGHTSPEED,1);
	} 
}

void ReleaseRack()
{
	Pull_Piston(Grabber);
}



int AutoModeThrower()
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
					case RACKPICK:PickRack();break;
					case RACKDROP:ReleaseRack();break;
					default:break;
				}
				uart_tx_str(COM3,"action=%d coordinate x= %d y= %d \n",RobotActions[i],CurrentPosition.x,CurrentPosition.y);
				//delay 2s to hold the car
				delay(3000);			
			}
			init=2;
		}
        return 1;
	}
	return 0;
}


void UARTOnReceiveHandler(const u8 received){
	
	if(ReceivedAction=='\0')
	{ReceivedAction=received;}
    return;
}


int main()
{
	rcc_init();
    ticks_init();  
	leds_init();
	buttons_init();
    //tft_init(1, BLACK, WHITE, RED, YELLOW);
    uart_init(COM3, 115200);
	uart_rx_init(COM3,&UARTOnReceiveHandler);
	  
	
	
	//initialize motor, prescalar 40, autoreload=6000
	//motor_init(MOTOR1, 39, AUTORELOAD,1,1);
	//motor_init(MOTOR2, 39, AUTORELOAD,1,1);
	//motor2

	
	
	
			//pc6=pwm1
			//pc7=pwm2
			//pa8=dir2
			//pc3=dir1
	//gpio_set(&PA8);
	//gpio_set(&PC3);
	////gpio_reset(&PC6);
	//gpio_reset(&PC7);
	
	
	uint32_t lastticks=get_ticks();
	//initialize linetracker
	lineTracker_init();
	//sonar_init();
	Piston_init();
     
	//enter thrower robot movement subroutine
	while(1)
    {
	    if(button_pressed(BUTTON1))
	    {
		led_on(LED1);
	    break;
	    }
    }
		delay(500);

		//CanEnterManual=AutoModeThrower();
    ManualMode();
	return 0;
}