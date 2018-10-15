#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "main.h"
#include "hwnormalMode.h"
#ifndef SERVOCW_H_
#define SERVOCW_H_

void MoveToLeftMost(int StartPosition,int Saparation)
{
	int this_ticks =get_ticks();
	int last_led_ticks=get_ticks();
	int ServoPosition=StartPosition;
	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		if(this_ticks-last_led_ticks<=1000&&(this_ticks-last_led_ticks)%10==0)
		{
			servo_control(SERVO1,ServoPosition-=Saparation);
		}
		else if(this_ticks-last_led_ticks>1000)
		{
			break;
		}
	}
}

void MoveToRightMost(int StartPosition,int Saparation)
{
	int this_ticks =get_ticks();
	int last_led_ticks=get_ticks();
	int ServoPosition=StartPosition;
	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		if(this_ticks-last_led_ticks<=1000&&(this_ticks-last_led_ticks)%10==0)
		{
			servo_control(SERVO1,ServoPosition+=Saparation);
		}
		else if(this_ticks-last_led_ticks>1000)
		{
			break;
		}
	}
}

void CW2()
{

	servo_init(SERVO1, 23, 60000, 2700);
	int this_ticks =get_ticks();
	//int last_led_ticks=get_ticks();
	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		if(button_pressed(BUTTON1))
		{
			MoveToRightMost(2700,(6300-2700)/100);
			MoveToLeftMost(6300,(6300-2700)/100);
		}
	}
}


int NumButton1Pressed=0;
int NumButton2Pressed=0;
int StartPosition=0;
int Saparation=14;
int But1State=0;
int But2State=0;
void RaiseDutyCycle();
void DropDutyCycle();
void GetInput()
{
	if(But1State==0&&button_pressed(BUTTON1))
	{
		But1State=1;
		NumButton1Pressed++;
	}
	else if(But1State==1&&!button_pressed(BUTTON1))
	{
		But1State=0;
	}
	if(But2State==0&&button_pressed(BUTTON2))
	{
		But2State=1;
		NumButton2Pressed++;
	}
	else if(But2State==1&&!button_pressed(BUTTON2))
	{
		But2State=0;
	}
}

int ticks()
{

	GetInput();
	if(NumButton1Pressed>0)
	{
		RaiseDutyCycle();
	}
	if(NumButton2Pressed>0)
	{
		DropDutyCycle();
	}
	return get_ticks();
}

void DropDutyCycle()
{
	int this_ticks =get_ticks();
	int last_led_ticks=get_ticks();
	int MotorPosition=StartPosition;
	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();
		GetInput();

		if(this_ticks-last_led_ticks<=1000&&(this_ticks-last_led_ticks)%100==0)
		{

			if(MotorPosition-Saparation<0&&MotorPosition-Saparation>=-1440)
			{
				motor_control(MOTOR1,-1*(MotorPosition-=Saparation),0);
			}
			else if(MotorPosition-Saparation>=0)
			{
				motor_control(MOTOR1,MotorPosition-=Saparation,1);
			}

		}
		else if(this_ticks-last_led_ticks>1000)
		{
			if(StartPosition - 144>=0)
			{motor_control(MOTOR1,StartPosition-=144,1);}
			else if(StartPosition - 144<0&&StartPosition - 144>=-1440)
			{motor_control(MOTOR1,-1*(StartPosition-=144),0);}
			NumButton2Pressed--;
			break;
		}
	}
}

void RaiseDutyCycle()
{
	int this_ticks =get_ticks();
	int last_led_ticks=get_ticks();
	int MotorPosition=StartPosition;
	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();
		GetInput();

		if(this_ticks-last_led_ticks<=1000&&(this_ticks-last_led_ticks)%100==0)
		{

			if(MotorPosition+Saparation>=0&&MotorPosition+Saparation<=1440)
			{
				motor_control(MOTOR1,(MotorPosition+=Saparation),1);
			}
			else if(MotorPosition+Saparation<0)
			{
				motor_control(MOTOR1,-1*(MotorPosition+=Saparation),0);
			}

		}
		else if(this_ticks-last_led_ticks>1000)
		{
			if(StartPosition + 144>=0&&StartPosition + 144<=1440)
			{motor_control(MOTOR1,StartPosition+=144,1);}
			else if(StartPosition + 144<0)
			{motor_control(MOTOR1,-1*(StartPosition+=144),0);}
			NumButton1Pressed--;
			break;
		}
	}
}

void CW4()
{

	motor_init(MOTOR1, 0, 1440,0,1);
	int this_ticks =ticks();
	while (1)
	{
		while (ticks() == this_ticks);
		this_ticks = ticks();
	}

}




void CW3()
{
	int button1_state=0;
	int button2_state=0;
	int magnitude=0;
	int TenthDutyCycle=720/10;
	motor_init(MOTOR1, 1, 720,magnitude,1);
	int this_ticks =get_ticks();
	//int last_led_ticks=get_ticks();

	while (1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		if(button1_state==0&&button_pressed(BUTTON1))
		{
			if(magnitude<=-72)
			{
				motor_control(MOTOR1,-1*(magnitude+=TenthDutyCycle),0);
				button1_state=1;
			}
			else if(magnitude>-72&&magnitude<=648)
			{
				motor_control(MOTOR1,magnitude+=TenthDutyCycle,1);
				button1_state=1;
			}
		}
		else if(button1_state==1&&!button_pressed(BUTTON1))
		{
			button1_state=0;
		}
		if(button2_state==0&&button_pressed(BUTTON2))
		{
			if(magnitude>=72)
			{
				motor_control(MOTOR1,magnitude-=TenthDutyCycle,1);
				button2_state=1;
			}
			else if(magnitude<72&&magnitude>=-648)
			{
				motor_control(MOTOR1,-1*(magnitude-=TenthDutyCycle),0);
				button2_state=1;
			}
		}
		else if(button2_state==1&&!button_pressed(BUTTON2))
		{
			button2_state=0;
		}
	}
}
#endif /* SERVOCW_H_ */
