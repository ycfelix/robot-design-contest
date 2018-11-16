//
//  servo.c
//  Experiment
//
//  Created by JQ on 16/11/2018.
//  Copyright © 2018 JQ. All rights reserved.
//

#include "rcc.h"
#include "ticks.h"
#include "gpio.h"
#include "leds.h"
#include "buttons.h"
#include "buzzer.h"
#include "uart.h"
#include "lcd_main.h"
#include "oled.h"
#include "camera.h"
#include "pwm.h"
#include "adc.h"
#include "main.h"


const int INITIAL_POSITION = 4700; // Initial position of servo (facing forward). Changed from 4500 to 4700;
const u16 LEFT_MAX_POSITION = 3100; // Changed from 2700 to 3100 for symmetry.
const u16 RIGHT_MAX_POSITION = 6300; // CHECKED
const u8 SERVO_UPDATE_RATE = 20;
const u16 SERVO_VALUE_CHANGE = 100;
enum direction {FORWARD, LEFT, RIGHT};

int main()
{

    rcc_init();
    ticks_init();
    leds_init();
    buttons_init();
    tft_init(1, BLACK, WHITE, RED, YELLOW);
    servo_init(SERVO1, 23, 60000, 4500);
    led_on(LED1);
    u16 servo_control_value = INITIAL_POSITION;
    u16 servo_target = INITIAL_POSITION;
    u16 button1_tracker = 0, button2_tracker = 0;
    u16 button1_validation = 1, button2_validation = 1;
    u8 servo_direction = FORWARD;
    //servo_control(SERVO1, LEFT_MAX_POSITION);

    while(1){
    static u32 this_ticks = 0;
    while (get_ticks() == this_ticks);
    this_ticks = get_ticks();
    static u32 servo_ticks = 0;
    if((this_ticks - servo_ticks) >= SERVO_UPDATE_RATE){
        servo_ticks = this_ticks;
        tft_clear();
        if(button_pressed(BUTTON1)){
            led_on(LED1);
            led_off(LED2);
            servo_target += SERVO_VALUE_CHANGE;
            //servo_direction = FORWARD;
            //tft_prints(0, 1, "FORWARD");
        }
        if(button_pressed(BUTTON2)){
            led_on(LED2);
            led_off(LED1);
            servo_target -= SERVO_VALUE_CHANGE;
            //servo_direction = LEFT;
            //tft_prints(0, 1, "LEFT");
        }
        if(button_pressed(BUTTON3)){
            servo_target = 4500;
            //servo_direction = RIGHT;
            //tft_prints(0, 1, "RIGHT");
        }
        /*
         if(servo_control_value <= (RIGHT_MAX_POSITION - SERVO_VALUE_CHANGE) && servo_direction == RIGHT){
         servo_control_value += SERVO_VALUE_CHANGE;
         servo_control(SERVO1, servo_control_value);
         }
         if(servo_control_value >= (LEFT_MAX_POSITION + SERVO_VALUE_CHANGE) && servo_direction == LEFT){
         servo_control_value -= SERVO_VALUE_CHANGE;
         servo_control(SERVO1, servo_control_value);
         }
         if(servo_direction == FORWARD){
         if(servo_control_value < INITIAL_POSITION){
         servo_control_value += SERVO_VALUE_CHANGE;
         servo_control(SERVO1, servo_control_value);
         }
         else if(servo_control_value > INITIAL_POSITION){
         servo_control_value -= SERVO_VALUE_CHANGE;
         servo_control(SERVO1, servo_control_value);
         }
         }
         */
        if(servo_target != servo_control_value){
            if(servo_control_value < servo_target && servo_control_value <= (RIGHT_MAX_POSITION - SERVO_VALUE_CHANGE)){
                servo_control_value += SERVO_VALUE_CHANGE;
                servo_control(SERVO1, servo_control_value);
            }
            if(servo_control_value > servo_target && servo_control_value >= (LEFT_MAX_POSITION + SERVO_VALUE_CHANGE)){
                servo_control_value -= SERVO_VALUE_CHANGE;
                servo_control(SERVO1, servo_control_value);
            }
        }
        tft_prints(0, 0, "%d", servo_control_value);
        tft_update();
        }
    }
}
