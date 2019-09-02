#pragma once
#ifndef SIMULATOR_H_
#define SIMULATOR_H_
#include<iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <vector>
using namespace std;
enum LED { LED1 = 1, LED2 = 2,LED3=3 };
enum Button { BUTTON1 = 1, BUTTON2 = 2, BUTTON3 = 3 };
enum Servo { SERVO1 = 1, SERVO2 = 2, SERVO3 = 3 };
enum Motor { MOTOR1 = 1, MOTOR2 = 2 };
vector<string> __cout;

clock_t background_serive()
{
	//stop
	if (GetAsyncKeyState('4') & 0x8000) 
	{
		//continue
		while (!(GetAsyncKeyState('5') & 0x8000))
		{
			//pass
		}
	}
	return clock();
}
clock_t(*get_ticks)() = background_serive;

void servo_init(Servo servo, int  prescaler, int autoreload, int initial)
{
	cout << " SERVO " << servo << " is on! " << " time= " << get_ticks() << endl;
}
void servo_control(Servo servo, int position)
{
	cout << " SERVO " << servo << " is on! " << "Position= " << position << " time= " << get_ticks() << endl;

}
void motor_init(Motor motor, int prescaler, int autoreload, int magnitude, int direction)
{
	cout << " MOTOR " << motor << " is on! " << " time= " << get_ticks() << endl;
}
void motor_control(Motor motor, int magnitude, int direction)
{
	cout << " MOTOR " << motor << " is on! " << "Position= " << magnitude << " direction= " << direction << " time= " << get_ticks() << endl;
}

namespace simple_mode 
{
	void led_on(LED led)
	{
		string target = string(" LED ") + to_string(led) + string(" is on!");
		std::vector<string>::iterator it = std::find(__cout.begin(), __cout.end(), target);

		if (it == __cout.end())
		{
			__cout.push_back(target);
			cout << " LED " << led << " is on! " << " time= " << get_ticks() << endl;
		}
	}
	void led_off(LED led)
	{

		string target = string(" LED ") + to_string(led) + string(" is on!");
		std::vector<string>::iterator it = std::find(__cout.begin(), __cout.end(), target);

		if (it != __cout.end())
		{
			__cout.erase(it);
			cout << " LED " << led << " is off! " << " time= " << get_ticks() << endl;
		}
	}
}
namespace complex_mode
{
	void led_on(LED led)
	{
		cout << " LED " << led << " is on! " << " time= " << get_ticks() << endl;
	}
	void led_off(LED led)
	{
		cout << " LED " << led << " is off! " << " time= " << get_ticks() << endl;
	}
}



void buzzer_on(void) 
{ 
	cout << " buzzer is on! " << " time= " << get_ticks() << endl; 
}
void buzzer_off(void) 
{
	cout << " buzzer is off! " << " time= " << get_ticks() << endl; 
}


bool button_pressed(Button button)
{
	static bool lock1 = false;
	static bool lock2 = false;
	static bool lock3 = false;
	if (button == BUTTON1 && (GetAsyncKeyState('1') & 0x8000))
	{
		if (!lock1)
		{
			lock1=true;
			cout << " Button " << button << " is on!" << " time= " << get_ticks() << endl;

		}
		return true;
	}
	else if (button == BUTTON2 && (GetAsyncKeyState('2') & 0x8000))
	{
		if (!lock2)
		{
			lock2 = true;
			cout << " Button " << button << " is on!" << " time= " << get_ticks() << endl;
		}
		return true;
	}
	else if (button == BUTTON3 && (GetAsyncKeyState('3') & 0x8000))
	{
		if (!lock3)
		{
			lock3 = true;
			cout << " Button " << button << " is on!" << " time= " << get_ticks() << endl;
		}
		return true;
	}
	if (lock1 && button == BUTTON1)
	{
		cout << " Button " << button << " is off!" << " time= " << get_ticks() << endl;
		lock1 = false;
	}
	if (lock2&& button == BUTTON2)
	{
		cout << " Button " << button << " is off!" << " time= " << get_ticks() << endl;
		lock2 = false;
	}
	if (lock3 && button == BUTTON3)
	{
		cout << " Button " << button << " is off!" << " time= " << get_ticks() << endl;
		lock3 = false;
	}
	return false;
}

#endif
