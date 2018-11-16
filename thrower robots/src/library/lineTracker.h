#ifndef __LINETRACKER_H
#define __LINETRACKER_H

#include "gpio.h"

// totally 2 linetrackers are used
typedef enum
{
	lineTracker1=0,
	lineTracker2=1
}lineTracker;


//init linetracker, assigned to PC3, PC4
void lineTracker_init(void);


//Read input from a specific linetracker, return 1 if sense white line, 0 otherwise
u8 ReadLineTracker(lineTracker);


#endif