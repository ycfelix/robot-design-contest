#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "main.h"
#include "hwnormalMode.h"
#include "servoHW.h"
using namespace std;

int Button1FirstPressed=0;
int Button1SecondPressed=0;

int Button2FirstPressed=0;
int Button2SecondPressed=0;

int Button3FirstPressed=0;
int Button3SecondPressed=0;

int Button1PressedState=0;
int Button2PressedState=0;
int Button3PressedState=0;

void BuzzForButton(int BuzzTime)
{
	int buzzer_state=0;
	int this_ticks = 0;
	int last_led_ticks = this_ticks;
	while (true)
	{
		if(BuzzTime==0){break;}

		while (clock() == this_ticks);
		this_ticks = clock();

		if((this_ticks-last_led_ticks)%300==0)
		{
			last_led_ticks=	this_ticks;
			if (buzzer_state == 0)
			{
				buzzer_on();
				buzzer_state = 1;
				BuzzTime--;
			}
			else if (buzzer_state == 1)
			{
				buzzer_off();
				buzzer_state = 0;
				BuzzTime--;
			}
		}
	}

}

void Classwork6()
{
	int singleton=0;
	int EnterOnlyOnce=0;

	while (true)
	{
		if(singleton==0&&button_pressed(BUTTON1))
		{
			singleton=1;
			EnterOnlyOnce=1;
		}
		else if(singleton==0&&button_pressed(BUTTON2))
		{
			singleton=2;
			EnterOnlyOnce=1;
		}
		else if(singleton==0&&button_pressed(BUTTON3))
		{
			singleton=3;
			EnterOnlyOnce=1;
		}
		else if(!button_pressed(BUTTON1)&&!button_pressed(BUTTON2)&&!button_pressed(BUTTON3))
		{
			singleton=0;
			EnterOnlyOnce=0;
		}

		if(EnterOnlyOnce!=0)
		{
			switch(singleton)
			{
			case 0:break;
			case 1:BuzzForButton(2);EnterOnlyOnce=0;break;
			case 2:BuzzForButton(4);EnterOnlyOnce=0;break;
			case 3:BuzzForButton(6);EnterOnlyOnce=0;break;
			}
		}

	}
}

void BeepPer100ms()
{
	int this_ticks = Clock();
	int CurrentTime = this_ticks;
	while (true)
	{
		while (Clock() == this_ticks);
		this_ticks = Clock();


		if((this_ticks-CurrentTime)==100)
		{
			CurrentTime=this_ticks;
			if(buzzer_state==0)
			{
				buzzer_on();
				buzzer_state=1;
			}
			else if(buzzer_state==1)
			{
				buzzer_off();
				buzzer_state=0;
				break;
			}
		}
	}
}





void GetButtonClickInput()
{
	if(Button1PressedState==0&&button_pressed(BUTTON1))
	{
		Button1PressedState=1;
		if(Button1FirstPressed==0)
		{
			Button1FirstPressed=get_ticks();
		}
		else
		{
			Button1SecondPressed=get_ticks();
		}
	}
	if(Button1PressedState==1&&!button_pressed(BUTTON1))
	{
		Button1PressedState=0;
	}

	if(Button2PressedState==0&&button_pressed(BUTTON2))
	{
		Button2PressedState=1;
		if(Button2FirstPressed==0)
		{
			Button2FirstPressed=get_ticks();
		}
		else
		{
			Button2SecondPressed=get_ticks();
		}
	}
	if(Button2PressedState==1&&!button_pressed(BUTTON2))
	{
		Button2PressedState=0;
	}

	if(Button3PressedState==0&&button_pressed(BUTTON3))
	{
		Button3PressedState=1;
		if(Button3FirstPressed==0)
		{
			Button3FirstPressed=get_ticks();
		}
		else
		{
			Button3SecondPressed=get_ticks();
		}
	}
	if(Button3PressedState==1&&!button_pressed(BUTTON3))
	{
		Button3PressedState=0;
	}
}

int Button1DoubleClicked()
{
	if(Button1FirstPressed!=0&&Button1SecondPressed!=0)
	{
		if(Button1SecondPressed-Button1FirstPressed<=300)
		{
			Button1FirstPressed=0;Button1SecondPressed=0;Button1PressedState=0;
			return 1;
		}
		else
		{
			Button1FirstPressed=0;Button1SecondPressed=0;Button1PressedState=0;
			return 0;
		}
	}
	return 0;
}

int Button2DoubleClicked()
{
	if(Button2FirstPressed!=0&&Button2SecondPressed!=0)
	{
		if(Button2SecondPressed-Button2FirstPressed<=300)
		{
			Button2FirstPressed=0;Button2SecondPressed=0;Button2PressedState=0;
			return 1;
		}
		else
		{
			Button2FirstPressed=0;Button2SecondPressed=0;Button2PressedState=0;
			return 0;
		}
	}
	return 0;
}

int Button3DoubleClicked()
{
	if(Button3FirstPressed!=0&&Button3SecondPressed!=0)
	{
		if(Button3SecondPressed-Button3FirstPressed<=300)
		{
			Button3FirstPressed=0;Button3SecondPressed=0;Button3PressedState=0;
			return 1;
		}
		else
		{
			Button3FirstPressed=0;Button3SecondPressed=0;Button3PressedState=0;
			return 0;
		}
	}
	return 0;
}


void Classwork4Rework()
{
	int LED1_state=0;
	int LED2_state=0;
	int Button1Double=0;
	int Button2Double=0;
	int last_led_ticks=clock();
	int this_ticks = clock();
	while(true)
	{
		while (clock() == this_ticks);
		this_ticks = clock();
		GetButtonClickInput();
		int button1Result=Button1DoubleClicked();
		int button2Result=Button2DoubleClicked();
		int button3Result=Button3DoubleClicked();
		if(button1Result==1)
		{
			this_ticks = clock();
			BeepPer100ms();
			last_led_ticks=clock();
			button1Result=0;
			if(Button1Double==1){Button1Double=0;}
			else
			{
				Button1Double=1;
			}
		}

		if(button2Result==1)
		{
			this_ticks = clock();
			BeepPer100ms();
			last_led_ticks=clock();
			button2Result=0;
			if(Button2Double==1){Button2Double=0;}
			else
			{
				Button2Double=1;
			}
		}
		if(button3Result==1)
		{
			this_ticks = clock();
			BeepPer100ms();
			last_led_ticks=clock();
			button3Result=0;
			if(Button1Double==1){Button1Double=0;}
			else{Button1Double=1;}
			if(Button2Double==1){Button2Double=0;}
			else{Button2Double=1;}
		}

		int temp=last_led_ticks;

		if(Button1Double==1)
		{
			if(this_ticks-temp==300)
			{
				last_led_ticks=this_ticks;
				if(LED1_state==0)
				{
					led_on(LED1);
					LED1_state=1;
				}
				else if(LED1_state==1)
				{
					led_off(LED1);
					LED1_state=0;
				}
			}
		}
		//else{led_off(LED1);LED1_state=0;}

		if(Button2Double==1)
		{
			if(this_ticks-temp==300)
			{
				last_led_ticks=this_ticks;

				if(LED2_state==0)
				{
					led_on(LED2);
					LED2_state=1;
				}
				else if(LED2_state==1)
				{
					led_off(LED2);
					LED2_state=0;
				}
			}
		}
		//else{led_off(LED2);LED2_state=0;}
	}
}
int main()

{
	//Classwork4Rework();
	//Classwork5();
	//Classwork6();
	//NormalMode();
	//testing();
	HW2();
    return 0;
}
