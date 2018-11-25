#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_tim.h"
#include "stdio.h"
#include "misc.h"
#include "gpio.h"

//call this to enable timer 3 and gpio stuff
void sonar_init();


//interrupt handler for open counter and close counter
void EXTI2_IRQHandler(void);


//call this and it will update the sonar value automatically
void sonar_start();

unsigned int sonar_get();

