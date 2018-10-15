#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "main.h"
using namespace std;
#ifndef HW1NORMALMODE_H_
#define HW1NORMALMODE_H_
Button BUTTON1=Button::Button1;
Button BUTTON2=Button::Button2;
Button BUTTON3=Button::Button3;
LED LED1=LED::Led1;
LED LED2=LED::Led2;

int EnterTime[3]={};
int Password[3]={};
int ExitPassword[3]={1};
int EnteredBonus=0;

int Button1PressedTime=0;
int Button2PressedTime=0;
int Button3PressedTime=0;
int Button1Release=1;
int Button2Release=1;
int Button3Release=1;


int LED1_state=0;
int LED2_state=0;
int buzzer_state=0;
int Button2FirstPressedTime=0;
int Button2SecondPressedTime=0;
int Button2State=0;

void SpecialMode();
void BonusMode();
void CheckExitBonus();

void CheckAnyButtonRelease()
{
	if(!button_pressed(BUTTON1))
	{
		Button1Release=1;
	}
	if(!button_pressed(BUTTON2))
	{
		Button2Release=1;
	}
	if(!button_pressed(BUTTON3))
	{
		Button3Release=1;
	}
}

void GetAllButtonClick()
{
	if(Button1Release==1&&button_pressed(BUTTON1))
		{
			Button1Release=0;
			Button1PressedTime=get_ticks();
		}
		if(Button2Release==1&&button_pressed(BUTTON2))
		{
			Button2Release=0;
			Button2PressedTime=get_ticks();
		}
		if(Button3Release==1&&button_pressed(BUTTON3))
		{
			Button3Release=0;
			Button3PressedTime=get_ticks();
		}
}

//check can enter the special mode,1 for can,0 for cant
int CanEnterSpecial()
{
	if(Button2FirstPressedTime!=0&&Button2SecondPressedTime!=0)
	{
		if(Button2SecondPressedTime-Button2FirstPressedTime<=300)
		{
			Button2FirstPressedTime=0;Button2SecondPressedTime=0;Button2State=0;
			return 1;
		}
		else
		{
			Button2FirstPressedTime=0;Button2SecondPressedTime=0;Button2State=0;
			return 0;
		}
	}
	return 0;

}
//simply get the BUTTON2 click input
void GetClickInput()
{
	if(Button2State==0&&button_pressed(BUTTON2))
	{
		Button2State=1;
		if(Button2FirstPressedTime==0)
		{
			Button2FirstPressedTime=get_ticks();
		}
		else
		{
			Button2SecondPressedTime=get_ticks();
		}
	}
	if(Button2State==1&&!button_pressed(BUTTON2))
	{
		Button2State=0;
	}
}






int Clock()
{
	GetAllButtonClick();
	CheckAnyButtonRelease();
	GetClickInput();
	CheckExitBonus();
	if(CanEnterSpecial()==1&&EnteredBonus==0)
	{
		cout<<"Enter special mode"<<endl;
		SpecialMode();
	}


	return get_ticks();
}


void SwitchLED()
{
	if (LED1_state == 1)
	{
		led_off(LED1);
		led_on(LED2);
		LED2_state = 1;
		LED1_state = 0;
	}
	else if (LED1_state == 0)
	{
		led_off(LED2);
		led_on(LED1);
		LED2_state = 0;
		LED1_state = 1;
	}
}

void BeepOnce()
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



void Sorting(int arr[],int n, int Pass[])
{

	int i, j;
	for (i = 0; i < 3; i++)
	{
	   for (j = 0; j < 2; j++)
	   {
	      if (arr[j] > arr[j+1])
	      {
	    	  int temp=arr[j];
	    	  arr[j]=arr[j+1];
	    	  arr[j+1]=temp;
	      }
	   }
	}

	for(int k=0;k<3;k++)
	{
		if(arr[k]==Button1PressedTime)
		{
			Pass[k]=1;
		}
		else if(arr[k]==Button2PressedTime)
		{
			Pass[k]=2;
		}
		else if(arr[k]==Button3PressedTime)
		{
			Pass[k]=3;
		}
	}


}



void FlashLED()
{
	int ActOnce=1;
	int this_ticks = Clock();
	int CurrentTime= this_ticks;
	while (true)
	{
		if(!button_pressed(BUTTON1)){break;}

		while (Clock() == this_ticks);
		this_ticks = Clock();

		while(button_pressed(BUTTON2)||button_pressed(BUTTON3))
		{
			this_ticks = Clock();
			if(button_pressed(BUTTON2)&&button_pressed(BUTTON3))
			{
				if((this_ticks-CurrentTime)>500)
				{
					CurrentTime=this_ticks;
					if(ActOnce>0)
					{
						BeepOnce();
						ActOnce--;

						EnterTime[0]=Button1PressedTime;
						EnterTime[1]=Button2PressedTime;
						EnterTime[2]=Button3PressedTime;

						if(EnterTime[0]!=0&&EnterTime[1]!=0&&EnterTime[2]!=0)
						{
							Sorting(EnterTime,3,Password);
							BonusMode();
						}
						Button1Release=0;
						Button2Release=0;
						Button3Release=0;
						Button1PressedTime=0;
						Button2PressedTime=0;
						Button3PressedTime=0;

						//hold since BUTTON1+ button 2 or 3 is pressed
					}
				}
			}
			else
			{
				ActOnce=1;
			}
		}
		if((this_ticks-CurrentTime)==300)
		{
			CurrentTime=this_ticks;
			SwitchLED();
			cout<<"switched LED! "<<endl;
			continue;
		}
		//special case since currentTime after pressing BUTTON2/3 is not updated
		else if((this_ticks-CurrentTime)>300)
		{
			CurrentTime=this_ticks;
		}
	}
}


int HoldFor500ms()
{
	int returncode=-1;
	int ActOnce=1;
	int this_ticks = Clock();
	int CurrentTime= this_ticks;

	while (Clock() == this_ticks);
	this_ticks = Clock();

	while(button_pressed(BUTTON1))
	{
		this_ticks=Clock();
		if(ActOnce>0)
		{
			SwitchLED();
			cout<<"Less than 500 ms, single switch!"<<endl;
			ActOnce--;
		}
		//if hold for more than 500ms
		if((this_ticks-CurrentTime)>500)
		{
			FlashLED();//embbeded the sleep function if button 1 or 2 pressed
			CurrentTime=Clock();
		}
	}
	return returncode;
}

void NormalMode()
{
	int this_ticks = get_ticks();
	while (true)
	{
		while (Clock() == this_ticks);
		this_ticks = Clock();
		HoldFor500ms();
	}
}


//can only use clock here, not Clock
void SpecialMode()
{
	led_off(LED1);
	led_off(LED2);
	LED1_state=0;
	LED2_state=0;

	GetClickInput();
	int this_ticks = get_ticks();
	while(CanEnterSpecial()==0)
	{
		this_ticks = get_ticks();
		GetClickInput();
		while (get_ticks() == this_ticks);
		this_ticks = get_ticks();

		//possible fix here, release the button doesnt off the led
		if(button_pressed(BUTTON1)&&!button_pressed(BUTTON2)&&!button_pressed(BUTTON3))
		{
			led_on(LED1);
			LED1_state=1;
			//led_off(LED2);
			LED2_state=0;
			//buzzer_off();
			buzzer_state=0;
		}
		else if(button_pressed(BUTTON2)&&!button_pressed(BUTTON1)&&!button_pressed(BUTTON3))
		{
			led_off(LED1);
			LED1_state=0;
			led_on(LED2);
			LED2_state=1;
			buzzer_off();
			buzzer_state=0;
		}
		else if(button_pressed(BUTTON3)&&!button_pressed(BUTTON1)&&!button_pressed(BUTTON2))
		{
			led_off(LED1);
			LED1_state=0;
			led_off(LED2);
			LED2_state=0;
			buzzer_on();
			buzzer_state=1;
		}
		else if(!button_pressed(BUTTON2)&&!button_pressed(BUTTON1)&&!button_pressed(BUTTON3))
		{
			led_off(LED1);
			LED1_state=0;
			led_off(LED2);
			LED2_state=0;
			buzzer_off();
			buzzer_state=0;
		}
		else
		{
			led_off(LED1);
			LED1_state=0;
			led_off(LED2);
			LED2_state=0;
			buzzer_off();
			buzzer_state=0;
		}

	}
}

int checkEnterAndExitPassword()
{
	for(int i=0;i<3;i++)
	{
		if(Password[i]!=ExitPassword[i])
		{
			return 0;
		}
	}
	return 1;
}



void FlashLEDByNumber(int FlashTime,int LEDNumber)
{
	int this_ticks = Clock();
	int CurrentTime= this_ticks;
	int RemainingFlashingTime=FlashTime*2;

	while(true)
	{
	while (Clock()  == this_ticks);
	this_ticks = Clock();

	if(RemainingFlashingTime<=0){break;}

	if((this_ticks-CurrentTime)==200&&RemainingFlashingTime>0)
	{
		CurrentTime=this_ticks;
		if (LED1_state == 1&&LEDNumber==1)
		{
			led_off(LED1);
			LED1_state = 0;
			RemainingFlashingTime--;
		}
		else if (LED1_state == 0&&LEDNumber==1)
		{
			led_on(LED1);
			LED1_state = 1;
			RemainingFlashingTime--;
		}
		else if (LED2_state==1&&LEDNumber==2)
		{
			led_off(LED2);
			LED2_state = 0;
			RemainingFlashingTime--;
		}
		else if (LED2_state==0&&LEDNumber==2)
		{
			led_on(LED2);
			LED2_state = 1;
			RemainingFlashingTime--;
		}
	}
	}

}

void WaitForTime(int time)
{
		led_off(LED1);
		led_off(LED2);
		LED1_state=0;
		LED2_state=0;
	int this_ticks =Clock();
	while (Clock() -this_ticks<time);
}


void BunusModeFlashing(int LEDFlashing)
{
		if(EnteredBonus==1)
		{
			WaitForTime(1000);
		}
		if(EnteredBonus==1)
		{
			FlashLEDByNumber(Password[0],LEDFlashing);
		}
		if(EnteredBonus==1)
		{
			WaitForTime(500);
		}
		if(EnteredBonus==1)
		{
			FlashLEDByNumber(Password[1],LEDFlashing);
		}
		if(EnteredBonus==1)
		{
			WaitForTime(500);
		}
		if(EnteredBonus==1)
		{
			FlashLEDByNumber(Password[2],LEDFlashing);
		}
}

void BonusMode()
{
	EnteredBonus=1;
	cout<<"Entered Bonus!"<<endl;
	cout<<"password"<<"-"<<Password[0]<<"-"<<Password[1]<<"-"<<Password[2]<<endl;
	Button1Release=0;
	Button2Release=0;
	Button3Release=0;
	Button1PressedTime=0;
	Button2PressedTime=0;
	Button3PressedTime=0;

	int this_ticks = get_ticks() ;
	int CurrentTime= this_ticks;

	int LEDFlashing=0;
	if (LED1_state == 1)
	{
		LEDFlashing=1;
	}
	else if (LED2_state==1)
	{
		LEDFlashing=2;
	}

	int ActOnce=1;
	while(EnteredBonus==1)
	{
		while (get_ticks() == this_ticks);
		this_ticks = Clock();




		if(ActOnce==1)
		{
			BunusModeFlashing(LEDFlashing);
			ActOnce--;
			CurrentTime=Clock();
		}

		if((this_ticks-CurrentTime)==400)
		{
			CurrentTime=this_ticks;
			if (LED1_state == 1&&LEDFlashing==1)
			{
				led_off(LED1);
				LED1_state = 0;
			}
			else if (LED1_state == 0&&LEDFlashing==1)
			{
				led_on(LED1);
				LED1_state = 1;
			}
			else if (LED2_state==1&&LEDFlashing==2)
			{
				led_off(LED2);
				LED2_state = 0;
			}
			else if (LED2_state==0&&LEDFlashing==2)
			{
				led_on(LED2);
				LED2_state = 1;

			}
		}
		if((this_ticks-CurrentTime)>400){CurrentTime=Clock();}


		if(button_pressed(BUTTON1)^button_pressed(BUTTON2)^button_pressed(BUTTON3))
		{
			ActOnce=1;
		}

	}

}

void CheckExitBonus()
{
	if(button_pressed(BUTTON1)&&button_pressed(BUTTON2)&&button_pressed(BUTTON3))
	{
		if(Button1PressedTime!=0&&Button2PressedTime!=0&&Button3PressedTime!=0)
		{
			EnterTime[0]=Button1PressedTime;
			EnterTime[1]=Button2PressedTime;
			EnterTime[2]=Button3PressedTime;
			Sorting(EnterTime,3,ExitPassword);
			if(checkEnterAndExitPassword()==1){EnteredBonus=0;}
		}
	}
}



#endif /* HW1_H_ */
