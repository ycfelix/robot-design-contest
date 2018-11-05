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

int led_state=0;

void UARTOnReceiveHandler(const u8 received)
{
		if(led_state==0)
		{
			led_on(LED1);
			led_state=1;			
		}
		else{led_off(LED1);led_state=0;}
    return;
}

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
		
		
    int lastticks=get_ticks();
    while(1)
		{
        if(lastticks!=get_ticks())
				{
            lastticks=get_ticks();
					
        }
				
				if(camera_ready()==1)
				{
					camera_receive_frame();
					camera_copy();
					camera_print(0,0);
				}
				
				if(ReadLineTracker(lineTracker1)==1){led_on(LED1);}
				else{led_off(LED1);}
				
				
    }        
}