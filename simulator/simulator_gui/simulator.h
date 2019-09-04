#pragma once
#ifndef SIMULATOR_H_
#define SIMULATOR_H_
#include<iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <vector>
using namespace std;
//model
enum LED { LED1 = 1, LED2 = 2,LED3=3 };
enum Button { BUTTON1 = 1, BUTTON2 = 2, BUTTON3 = 3 };
enum Servo { SERVO1 = 1, SERVO2 = 2, SERVO3 = 3 };
enum Motor { MOTOR1 = 1, MOTOR2 = 2 };
bool Buttons[]={false,false,false};
bool LEDs[]={false,false,false};
bool Buzzer=false;
static clock_t(*get_ticks)() = clock;

void servo_control(Servo servo, int position)
{

}
void motor_control(Motor motor, int magnitude, int direction)
{

}

void led_on(LED led)
{
    LEDs[static_cast<int>(led)-1]=true;
}
void led_off(LED led)
{
    LEDs[static_cast<int>(led)-1]=false;
}

void buzzer_on()
{
    Buzzer=true;
}

void buzzer_off()
{
    Buzzer=false;
}

bool check_keypress(char key){
    if(GetAsyncKeyState(key)&0x8000){
        return true;
    }
    return false;
}


bool button_pressed(Button button)
{
    if(!check_keypress('1')){
        Buttons[0]=false;
    }
    if(!check_keypress('2')){
        Buttons[1]=false;
    }
    if(!check_keypress('3')){
        Buttons[2]=false;
    }

    if(button==BUTTON1&&check_keypress('1'))
    {
        Buttons[static_cast<int>(button)-1]=true;
        return true;
    }
    else if(button==BUTTON2&&check_keypress('2'))
    {
        Buttons[static_cast<int>(button)-1]=true;
        return true;
    }
    else if(button==BUTTON3&&check_keypress('3'))
    {
        Buttons[static_cast<int>(button)-1]=true;
        return true;
    }
    return false;
}

#endif
