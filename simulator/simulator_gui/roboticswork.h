//viewModel
#ifndef ROBOTICSWORK_H
#define ROBOTICSWORK_H
#include"simulator.h"
#include <iostream>
void robotics_work(){

    int ticks = get_ticks();
    int last_tick=get_ticks();
    bool lock=false;
    while(true){
        if (get_ticks() == ticks) { continue; }
        if (button_pressed(BUTTON1)&&!lock)
        {
           lock=true;
           last_tick=get_ticks();
           led_on(LED1);
           //std::cout<<last_tick<<endl;
        }
        if(lock){
            //blink every 500ms
            if(get_ticks()-last_tick>=500){
                led_off(LED1);
            }
            if(get_ticks()-last_tick>=1000){
                lock=false;
            }
        }
        if(button_pressed(BUTTON2)){
            led_on(LED2);
        }
        else{
            led_off(LED2);
        }
    }
}
#endif // ROBOTICSWORK_H
