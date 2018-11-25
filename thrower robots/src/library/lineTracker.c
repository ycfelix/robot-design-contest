#include "lineTracker.h"

//using gpio 8
# define LineTracker1 &PA7
//using gpio 7
# define LineTracker2 &PA6

const GPIOPin* LineTrackers[]={LineTracker1,LineTracker2};

 
void lineTracker_init(void)
{
	gpio_init(LineTracker1, GPIO_Mode_IPU);
	gpio_init(LineTracker2, GPIO_Mode_IPU);
}


//return 1 if read white lines, return 0 if read background
//update: 1 if black, 0 if white
u8 ReadLineTracker(lineTracker linetracker)
{
	return !gpio_read(LineTrackers[linetracker]);
}
