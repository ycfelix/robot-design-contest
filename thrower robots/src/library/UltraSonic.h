#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_tim.h"
#include "stdio.h"
#include "misc.h"

volatile uint8_t FLAG_ECHO = 0;
volatile uint16_t SonarValue;

void SetSysClockTo72(void);

//init ultra sonic
void sonar_init();

//idk wtf is it
void EXTI0_IRQHandler(void);

//send pluse
void sonar_start();

//receive singal
unsigned int sonar_get();

//also dk wtf is it
void TIM4_IRQHandler(void);
