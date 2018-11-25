#ifndef __PISTON_H
#define __PISTON_H

#include "gpio.h"

// totally 2 solenoid are used
typedef enum
{
	Thrower=0,
	Grabber=1
}PISTON;


//init PISTON
void Piston_init(void);


//Set output
void Push_Piston(PISTON);

void Pull_Piston(PISTON);


#endif