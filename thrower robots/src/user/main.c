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
   ticks_init();  
		leds_init();
		buttons_init();
		adc_channel_init(ADC_IO_1);
		adc_init();
    //call uart_rx_init 
		lineTracker_init();
		tft_init(PIN_ON_RIGHT,GREY,RED,WHITE,BLUE);
		tft_clear();
	  camera_init(RGBColour);
    //uart_rx_init(COM1,&UARTOnReceiveHandler);
		NVIC_Config();
		CH_SR04_Init();
		
		
    int lastticks=get_ticks();
		int temp=lastticks;
    while(1)
		{
						while( lastticks==get_ticks()){}
            lastticks=get_ticks();
							
							
						if(lastticks-temp==500)
						{
							int distance=Senor_Using();
							tft_prints(0,0,"sonar position %f\n LineTracker state %d",distance,ReadLineTracker(lineTracker1));
							tft_update();
							temp=lastticks;
						}
						delay(2000);
						if(lastticks-temp>500)
						{temp=lastticks;}
						
					
				
					
    	
    
    
						
						////tft_prints(0,0,"sonar position %d\n LineTracker state %d",sonar_get(),ReadLineTracker(lineTracker1));
						//tft_update();
        		
				
				if(ReadLineTracker(lineTracker1)==1){led_on(LED1);}
				else{led_off(LED1);}
				
				
    }        
}