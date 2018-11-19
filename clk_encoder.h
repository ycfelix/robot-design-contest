#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"


void encoder_init();
void encoder_update();

typedef enum {
	FORWARD,
	REVERSE
} CAR_MODE;