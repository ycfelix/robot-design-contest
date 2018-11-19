#include "clk_encoder.h"


void encoder_init(){
    
    GPIO_InitTypeDef GPIO_InitStruct;

    // Step 1: Initialize GPIO as input for rotary encoder
    // PB6 (TIM4_CH2) (encoder pin A), PB7 (TIM4_CH3) (encoder pin B)
		// CAMERA 7 and 8
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
 
  	// Step 2: Setup TIM2 for encoder input
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12,
        TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
    TIM_Cmd(TIM4, ENABLE);
}

void encoder_update(uint16_t *count, CAR_MODE *mode){
		if (TIM4->CNT >= 1560) {
			TIM4->CNT &= 0;
			
		
			*count += 1;
		}
}
