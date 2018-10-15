
#include<iostream>
#ifndef MAIN_H_
#define MAIN_H_
using namespace std;
enum LED{Led1=1,Led2=2};
enum Button{Button1=1,Button2=2,Button3=3};
enum Servo{SERVO1=1,SERVO2=2,SERVO3=3};
enum Motor{MOTOR1=1,MOTOR2=2};
clock_t (*get_ticks)()=clock;

void leds_init(void){}
void buzzer_init(void){}
void buttons_init(void){}
void servo_init(Servo servo, int  prescaler, int autoreload, int initial)
{
	cout<<" SERVO "<<servo<<" is on! "<<" time= "<< get_ticks()<<endl;
}
void servo_control(Servo servo, int position)
{
	cout<<" SERVO "<<servo<<" is on! "<<"Position= "<<position<<" time= "<< get_ticks()<<endl;

}
void motor_init(Motor motor, int prescaler, int autoreload, int magnitude, int direction)
{
	cout<<" MOTOR "<<motor<<" is on! "<<" time= "<< get_ticks()<<endl;
}
void motor_control(Motor motor, int magnitude, int direction)
{
	cout<<" MOTOR "<<motor<<" is on! "<<"Position= "<<magnitude<<" direction= "<<direction<<" time= "<< get_ticks()<<endl;
}


void led_on(LED led){cout<<" LED "<<led<<" is on! "<<" time= "<< get_ticks()<<endl;}
void led_off(LED led){cout<<" LED "<<led<<" is off! "<<" time= "<<get_ticks()<<endl;}
void buzzer_on(void){cout<<" buzzer is on! "<<" time= "<< get_ticks()<<endl;}
void buzzer_off(void){cout<<" buzzer is off! "<<" time= "<< get_ticks()<<endl;}

bool button_pressed(Button button)
{
	static int counter1=0;
	static int counter2=0;
	static int counter3=0;
	if(button==Button1&& (GetAsyncKeyState( '1' ) & 0x8000) )
	{
		if(counter1==0)
		{
			counter1++;
			cout<<" Button "<<button<<" is on!"<<" time= "<<get_ticks()<<endl;
		}
		return true;
	}
	else if( button==Button2&& (GetAsyncKeyState( '2' ) & 0x8000) )
	{
		if(counter2==0)
		{
			counter2++;
			cout<<" Button "<<button<<" is on!"<<" time= "<<get_ticks()<<endl;
		}
		return true;
	}
	else if( button==Button3&& (GetAsyncKeyState( '3' ) & 0x8000) )
	{
		if(counter3==0)
		{
			counter3++;
			cout<<" Button "<<button<<" is on!"<<" time= "<<get_ticks()<<endl;
		}
		return true;
	}
	if(counter1!=0&&button==Button1)
	{
		cout<<" Button "<<button<<" is off!"<<" time= "<<get_ticks()<<endl;
		counter1=0;
	}
	if(counter2!=0&&button==Button2)
	{
		cout<<" Button "<<button<<" is off!"<<" time= "<<get_ticks()<<endl;
		counter2=0;
	}
	if(counter3!=0&&button==Button3)
	{
		cout<<" Button "<<button<<" is off!"<<" time= "<<get_ticks()<<endl;
		counter3=0;
	}



	return false;

}

#endif /* MAIN_H_ */
