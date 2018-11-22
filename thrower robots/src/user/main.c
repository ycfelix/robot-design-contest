#include "main.h"
#include "rcc.h"
#include "ticks.h"
#include "gpio.h"
#include "uart.h"
int main() {
    // Initialize Everything Here
    rcc_init();
    ticks_init();        
    uart_init(COM3,9600);
    uint32_t lastticks=get_ticks();
    while(1){
        if(lastticks!=get_ticks()){
            lastticks=get_ticks();
            if(!(lastticks%250) ){
                //uart_tx_str(COM3
                //,"This text is sent every 250 ms \n"); 
                
            }
        }
    }        
}