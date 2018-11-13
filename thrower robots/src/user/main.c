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


//direction
typedef enum {EAST=0,WEST=180,NORTH=90,SOUTH=270,CLKWISE,ANTICLKWISE}CompusDir;

//a set of robot action, will go from start zone to throwing zone
CompusDir RobotActions[]={WEST,WEST,WEST,WEST,EAST,CLKWISE,
		NORTH,NORTH,NORTH,NORTH,NORTH,CLKWISE,EAST,EAST,EAST,EAST};

		//size of action array
int Actions_Length=sizeof(RobotActions)/sizeof(RobotActions[0]);
		
		//coordinate of the robot
Coordinate CurrentPosition;
		
//debounce variable to prevent mutiple access
int LT1_state = 0;

// Move east until it sees a white line and then stop
void MoveEast(int dir)
{
	//start moving
	motor_control(MOTOR1,6000,dir);
	motor_control(MOTOR2,6000,dir);
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
				motor_control(MOTOR1,0,dir);
				motor_control(MOTOR2,0,dir);
				//update the robots coordinate
				CurrentPosition.x++;
				return;
			}
	}
}

void MoveWest(int dir)
{
	motor_control(MOTOR1,6000,dir);
	motor_control(MOTOR2,6000,dir);
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
				motor_control(MOTOR1,0,dir);
				motor_control(MOTOR2,0,dir);
				CurrentPosition.x--;
				return;
			}
	}
}

void MoveNorth(int dir)
{
	motor_control(MOTOR1,6000,dir);
	motor_control(MOTOR2,6000,dir);
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
				motor_control(MOTOR1,0,dir);
				motor_control(MOTOR2,0,dir);
				CurrentPosition.y--;
				return;
			}
	}
}

void MoveSouth(int dir)
{
	motor_control(MOTOR1,6000,dir);
	motor_control(MOTOR2,6000,dir);
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
				motor_control(MOTOR1,0,dir);
				motor_control(MOTOR2,0,dir);
				CurrentPosition.y++;
				return;
			}
	}
}


void TurnClockWise()
{
	
		motor_control(MOTOR1,6000,1);
		motor_control(MOTOR2,6000,-1);
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
					motor_control(MOTOR1,0,1);
				  motor_control(MOTOR2,0,1);
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


void Thrower()
{
	
	//initialize current position=5,5 coordinate
	CurrentPosition.x=5;
	CurrentPosition.y=5;
	
  //init enter once only
	int init=1;
	
	//initial direction is west
	CompusDir direction=WEST;
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
					case EAST:MoveEast(abs(RobotActions[i]-direction)==180?dir*=-1:dir);direction=EAST;break;
					case WEST:MoveWest(abs(RobotActions[i]-direction)==180?dir*=-1:dir);direction=WEST;break;
					case NORTH:MoveNorth(abs(RobotActions[i]-direction)==180?dir*=-1:dir);direction=NORTH;break;
					case SOUTH:MoveSouth(abs(RobotActions[i]-direction)==180?dir*=-1:dir);direction=SOUTH;break;
					case CLKWISE:TurnClockWise();break;
					default:break;
				}
				//delay 2s to hold the car
				delay(2000);
				
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
	
	//initialize motor, prescalar 23, autoreload=60000
	motor_init(MOTOR1, 23, 60000,0,1);
	motor_init(MOTOR2, 23, 60000,0,1);
	
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
	Thrower();
	return 0;
}

