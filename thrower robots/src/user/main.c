#include "main.h"
#include "rcc.h"
#include "ticks.h"
#include "gpio.h"
#include "uart.h"
#include "lcd_main.h"
#include "leds.h"
#include "buttons.h"
#include "adc.h"
#include "camera.h"
#include "lineTracker.h"
#include "Sonar.h"

int led_state=0;

 

int main() 
{
    // Initialize Everything Here
    rcc_init();
	//gpio_rcc_init(GPIOA);
    ticks_init();  
		leds_init();
		//tim_rcc_init(TIM2);
		//buttons_init();
		//adc_channel_init(ADC_IO_1);
		//adc_init();
    //call uart_rx_init 
		//lineTracker_init();
		tft_init(PIN_ON_RIGHT,GREY,RED,WHITE,BLUE);
		tft_clear();
	  //camera_init(RGBColour);
    //uart_rx_init(COM1,&UARTOnReceiveHandler);
		//NVIC_Config();
		delay_init(72);
	  CH_SR04_Init();
		
		
    int lastticks=get_ticks();
		int distance=0;
    while(1)
		{
						while( lastticks==get_ticks()){}
            lastticks=get_ticks();
							
							
						//delay(2000);
							
							if(lastticks%100==0)
							{
								distance=Senor_Using();
							}
							

						tft_prints(0,0,"sonar position%d time=%d",distance,lastticks);
							tft_update();
					
				
					
    	
    
    
						
						////tft_prints(0,0,"sonar position %d\n LineTracker state %d",sonar_get(),ReadLineTracker(lineTracker1));
						//tft_update();
        		
				
				if(distance>100){led_on(LED2);}
				else{led_off(LED2);}
				//if(distance<100&&distance>0){led_on(LED1);}
				//else{led_off(LED1);}
				//if(ReadLineTracker(lineTracker1)==1){led_on(LED1);}
				//else{led_off(LED1);}
				
				
    }        
}