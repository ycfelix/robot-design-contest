#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_tim.h"
#include "stdio.h"
#include "misc.h"
#include "main.h"
#include "rcc.h"
#include "ticks.h"
#include "gpio.h"


void sonar_init();

void EXTI2_IRQHandler(void);

void sonar_start();

unsigned int sonar_get();

