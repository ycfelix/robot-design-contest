#include "Piston.h"

//using gpio 5
# define Piston1 &PA5
//using gpio 4
# define Piston2 &PA4

const GPIOPin* Pistons[]={Piston1,Piston2};

 
void Piston_init(void)
{
	gpio_init(Piston1, GPIO_Mode_IPD);
	gpio_init(Piston2, GPIO_Mode_IPD);
}

//Set output
void Push_Piston(PISTON piston)
{ 
    gpio_write(Pistons[piston],1);
}

void Pull_Piston(PISTON piston)
{
    gpio_write(Pistons[piston],0);
}