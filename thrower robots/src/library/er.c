#include "main.h"
#include "rcc.h"
#include "ticks.h"
#include "gpio.h"
#include "uart.h"
#include "lcd_main.h"
#include "pwm.h"
#include "lineTracker.h"
#include "leds.h"
#include "buttons.h"

//coordinate structure
typedef struct
{
	int x;
	int y;
} Coordinate;

//not useful for now 
enum Direction{FORWARD=1,BACKWARD=-1};

const int SPEED=6000/5;


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
				delay(5000);			
			}
			init=2;
		}
	}
}
int main()
{
	rcc_init();
	//gpio_rcc_init(GPIOA);
  ticks_init();  
	leds_init();
	buttons_init();
	
	//initialize motor, prescalar 19, autoreload=720
	motor_init(MOTOR1, 39, 6000,1,1);
	motor_init(MOTOR2, 39, 6000,1,1);
	
	//initialize linetracker
	lineTracker_init();

	//enter thrower robot movement subroutine
	while(1)
{
	if(button_pressed(BUTTON1))
	{
		break;
	}
}
	AutoModeThrower();
	return 0;
}

