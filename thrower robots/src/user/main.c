#include "main.h"
#include "rcc.h"
#include "ticks.h"
#include "gpio.h"
#include "uart.h"
#include "lcd_main.h"
#include "pwm.h"
#include "lineTracker.h"
#include "leds.h"


typedef struct
{
	int x;
	int y;
} Coordinate;

enum Direction{FORWARD=1,BACKWARD=-1};

typedef enum {EAST=0,WEST=180,NORTH=90,SOUTH=270,CLKWISE,ANTICLKWISE}CompusDir;

CompusDir RobotActions[]={WEST,WEST,WEST,WEST,EAST,CLKWISE,
		NORTH,NORTH,NORTH,NORTH,NORTH,CLKWISE,EAST,EAST,EAST,EAST};
int Actions_Length=sizeof(RobotActions)/sizeof(RobotActions[0]);
Coordinate CurrentPosition;

// they will stop when they see a white line
void MoveEast(int dir)
{
	int LT1_state = 0;
	motor_control(MOTOR1,72,dir);
	motor_control(MOTOR2,72,dir);
	int this_ticks = get_ticks();

	while (1)
		{
			while (get_ticks() == this_ticks);
			this_ticks = get_ticks();

			if(LT1_state==1)
			{
				break;
			}


			//Stop when It read white lines
			if(ReadLineTracker(lineTracker1)==1&&LT1_state==0)
			{
				LT1_state=1;
				motor_control(MOTOR1,0,dir);
				motor_control(MOTOR2,0,dir);
				CurrentPosition.x++;
			}
		}
}

void MoveWest(int dir)
{
	int LT1_state = 0;
	motor_control(MOTOR1,72,dir);
	motor_control(MOTOR2,72,dir);
	int this_ticks = get_ticks();

	while (1)
		{
			while (get_ticks() == this_ticks);
			this_ticks = get_ticks();

			if(LT1_state==1)
			{
				break;
			}


			//Stop when It read white lines
			if(ReadLineTracker(lineTracker1)==1&&LT1_state==0)
			{
				LT1_state=1;
				motor_control(MOTOR1,0,dir);
				motor_control(MOTOR2,0,dir);
				CurrentPosition.x--;
			}
		}
}

void MoveNorth(int dir)
{
	int LT1_state = 0;
	motor_control(MOTOR1,72,dir);
	motor_control(MOTOR2,72,dir);
	int this_ticks = get_ticks();

	while (1)
		{
			while (get_ticks() == this_ticks);
			this_ticks = get_ticks();

			if(LT1_state==1)
			{
				break;
			}


			//Stop when It read white lines
			if(ReadLineTracker(lineTracker1)==1&&LT1_state==0)
			{
				LT1_state=1;
				motor_control(MOTOR1,0,dir);
				motor_control(MOTOR2,0,dir);
				CurrentPosition.y--;
			}
		}
}

void MoveSouth(int dir)
{
	int LT1_state = 0;
	motor_control(MOTOR1,72,dir);
	motor_control(MOTOR2,72,dir);
	int this_ticks = get_ticks();

	while (1)
		{
			while (get_ticks() == this_ticks);
			this_ticks = get_ticks();

			if(LT1_state==1)
			{
				break;
			}


			//Stop when It read white lines
			if(ReadLineTracker(lineTracker1)==1&&LT1_state==0)
			{
				LT1_state=1;
				motor_control(MOTOR1,0,dir);
				motor_control(MOTOR2,0,dir);
				CurrentPosition.y++;
			}
		}
}


void TurnClockWise()
{
	int LT1_state = 0;
		motor_control(MOTOR1,72,1);
		motor_control(MOTOR2,72,-1);
		int this_ticks = get_ticks();

		while (1)
			{
				while (get_ticks() == this_ticks);
				this_ticks = get_ticks();

				if(LT1_state==1)
				{
					break;
				}


				//Stop when It read white lines
				if(ReadLineTracker(lineTracker1)==1&&LT1_state==0)
				{
					LT1_state=1;
				}
			}
}

int abs(int num)
{
	if(num<0){num*=0;}
	
	return num;
}


void Thrower()
{
	CurrentPosition.x=5;
	CurrentPosition.y=5;
	int LT1_state=0;
	int LT2_state=0;
	int magnitude=0;
	int TenthDutyCycle=720/10;
	int init=0;
	CompusDir direction=WEST;
	motor_init(MOTOR1, 1, 720,magnitude,1);
	motor_init(MOTOR2, 1, 720,magnitude,1);
	lineTracker_init();
	int this_ticks =get_ticks();
	//int last_led_ticks=get_ticks();

	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		//only enter once for getting the car to start
		if(init==0&&ReadLineTracker(lineTracker1)==1)
		{
			motor_control(MOTOR1,TenthDutyCycle,direction);
			motor_control(MOTOR2,TenthDutyCycle,direction);
			init=1;
			LT1_state=1;
		}

		if(init==1)
		{
			int dir=1;
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
	Thrower();
	return 0;
}

