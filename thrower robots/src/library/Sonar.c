#include "Sonar.h"
#include "leds.h"
#include "ticks.h"
int overcount=0;


void NVIC_Config(void)
{
NVIC_InitTypeDef NVIC_InitStructer;

NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

NVIC_InitStructer.NVIC_IRQChannelPreemptionPriority=0;
NVIC_InitStructer.NVIC_IRQChannelSubPriority=0;
NVIC_InitStructer.NVIC_IRQChannel=TIM6_IRQn;
NVIC_InitStructer.NVIC_IRQChannelCmd=ENABLE;

NVIC_Init(&NVIC_InitStructer);
}


void CH_SR04_Init(void)
{
GPIO_InitTypeDef GPIO_InitStructer;
TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructer;

RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);

GPIO_InitStructer.GPIO_Speed=GPIO_Speed_50MHz;
GPIO_InitStructer.GPIO_Mode=GPIO_Mode_Out_PP;
GPIO_InitStructer.GPIO_Pin=GPIO_Pin_1;
GPIO_Init(GPIOA, &GPIO_InitStructer);
GPIO_ResetBits(GPIOA,GPIO_Pin_1);

GPIO_InitStructer.GPIO_Mode=GPIO_Mode_IPU;
GPIO_InitStructer.GPIO_Pin=GPIO_Pin_2;
GPIO_Init(GPIOA, & GPIO_InitStructer);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);

RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
TIM_DeInit(TIM6);
TIM_TimeBaseInitStructer.TIM_Period=999;//?????1000
TIM_TimeBaseInitStructer.TIM_Prescaler=71; //????72
TIM_TimeBaseInitStructer.TIM_ClockDivision=TIM_CKD_DIV1;//???
TIM_TimeBaseInitStructer.TIM_CounterMode=TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM6,&TIM_TimeBaseInitStructer);

TIM_ClearFlag(TIM6, TIM_FLAG_Update);
TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);//??????
NVIC_Config();
TIM_Cmd(TIM6,DISABLE);//???????

}
static void Delay_Ms(uint16_t time)  //????
{ 
	uint16_t i,j;
	for(i=0;i<time;i++)
  		for(j=0;j<10260;j++);
}
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
** ????: Delay_Ms_Us
** ????: ??1us (?????????????)
** ????:time (us) ??time<65535				 
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
static void Delay_Us(uint16_t time)  //????
{ 
	uint16_t i,j;
	for(i=0;i<time;i++)
  		for(j=0;j<9;j++);
}




static u32 GetEchoTimer(void)
{
        u32 t = 0;
        t = overcount*1000;//??MS
        t += TIM_GetCounter(TIM6);//??US
	      TIM6->CNT = 0;  //?TIM2???????????
				Delay_Ms(50);
        return t;
}


static void OpenTimerForHc()        //?????
{
        TIM_SetCounter(TIM6,0);//????
        overcount = 0;
        TIM_Cmd(TIM6, ENABLE);  //??TIMx??

}
u16 Senor_Using(void)
{
u16 length=0,sum=0;
u16 tim;
int i=0;

while(i<=5){
PAout(1)=1; 
Delay_Us(200); 
PAout(1)=0;
	Delay_Us(200); 
PAout(1)=1; 
Delay_Us(200); 
PAout(1)=0;

while(PAin(2)==0);
OpenTimerForHc();

i+=1; 
	

while(PAin(2)==1){};
TIM_Cmd(TIM6,DISABLE);
led_on(LED1);
tim=GetEchoTimer();

length=tim;//??????????

sum=length+sum;
}
length=sum/5;
led_off(LED1);
return length;//?????????
}



void TIM6_IRQHandler(void) //??,????????,??????????,??????????
{
if(TIM_GetITStatus(TIM6,TIM_IT_Update)!=RESET)
{
TIM_ClearITPendingBit(TIM6,TIM_IT_Update);//??????
overcount++;
 
}
}

