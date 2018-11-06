#include "sys.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"
#include "ticks.h"
#include "delay.h"
#define uint unsigned int

#define TRIG_Send  PAout(13)
#define ECHO_Reci  PAin(14)

void CH_SR04_Init(void);
float Senor_Using(void);
void NVIC_Config(void);
