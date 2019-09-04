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
bool buttons[]={false,false,false};
bool LEDs[]={false,false,false};

static clock_t(*get_ticks)() = clock;

void servo_control(Servo servo, int position)
{

}
void motor_control(Motor motor, int magnitude, int direction)
{

}


void led_on(LED led)
{

}
void led_off(LED led)
{

}



void buzzer_on()
{

}

void buzzer_off()
{

}


bool button_pressed(Button button)
{
    switch(button)
    {
        case BUTTON1:break;
        case BUTTON2:break;
        case BUTTON3:break;
        default:break;
    }
}

#endif
