#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "main.h"
#include "hwnormalMode.h"
#ifndef SERVOHW_H_
#define SERVOHW_H_

int b1Pressed=0;
int counter=0;
//RGB as initialize
Servo servos[3]={SERVO1,SERVO2,SERVO3};

void ReverseOrder()
{
	int nowCount=counter;

	if(counter+1>=3)
	{	Servo temp=servos[0];
		servos[0]=servos[1];
		servos[1]=temp;
	}
	else if(counter+1==2)
	{
		Servo temp=servos[0];
		servos[0]=servos[2];
		servos[2]=temp;
	}
	else if(counter+1==1)
	{
		Servo temp=servos[1];
		servos[1]=servos[2];
		servos[2]=temp;
	}
}

int GetCurrentClock()
{
	if(b1Pressed==0&&button_pressed(BUTTON1))
	{
		b1Pressed=1;
		ReverseOrder();

	}
	else if(b1Pressed==1&&!button_pressed(BUTTON1))
	{
		b1Pressed=0;
	}

	return get_ticks();
}



void MoveToLeftMost(Servo SERVO,int StartPosition,int Saparation, int counter)
{
	int this_ticks =get_ticks();
	int last_led_ticks=get_ticks();
	int ServoPosition=StartPosition;
	while (1)
	{
		//exit condition if suddenly clicked button
		//if(servos[counter]!=SERVO){servo_control(SERVO,0);break;}



		while (GetCurrentClock() == this_ticks);
		this_ticks = GetCurrentClock();

		if(this_ticks-last_led_ticks<=1500&&(this_ticks-last_led_ticks)%15==0)
		{
			servo_control(SERVO,ServoPosition-=Saparation);
		}
		else if(this_ticks-last_led_ticks>1500)
		{
			servo_control(SERVO,0);
			break;
		}
	}
}

void MoveToRightMost(Servo SERVO,int StartPosition,int Saparation, int counter)
{
	int this_ticks =GetCurrentClock();
	int last_led_ticks=GetCurrentClock();
	int ServoPosition=StartPosition;
	while (1)
	{
		//exit condition if suddenly clicked button
		//if(servos[counter]!=SERVO){servo_control(SERVO,0);break;}

		while (GetCurrentClock() == this_ticks);
		this_ticks = GetCurrentClock();

		if(this_ticks-last_led_ticks<=1500&&(this_ticks-last_led_ticks)%15==0)
		{
			servo_control(SERVO,ServoPosition+=Saparation);
		}
		else if(this_ticks-last_led_ticks>1500)
		{
			servo_control(SERVO,6000);
			break;
		}
	}
}

void HW2()
{

	servo_init(SERVO1, 9, 6000,0);
	servo_init(SERVO2, 9, 6000,0);
	servo_init(SERVO3, 9, 6000,0);
	int this_ticks =get_ticks();

	//int last_led_ticks=get_ticks();
	while (1)
	{
		while (GetCurrentClock() == this_ticks);
		this_ticks = GetCurrentClock();

			MoveToRightMost(servos[counter],0,(6000)/100,counter);
			MoveToLeftMost(servos[counter],6000,(6000)/100,counter);
			counter++;
			if(counter>=3)
			{
				counter=0;
			}
	}
}



#endif /* SERVOHW_H_ */
