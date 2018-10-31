#include "lineTracker.h"

# define LineTracker1 &PC3
# define LineTracker2 &PC4

const GPIOPin* LineTrackers[]={LineTracker1,LineTracker2};


void lineTracker_init(void)
{
	gpio_init(LineTracker1, GPIO_Mode_IPU);
	gpio_init(LineTracker2, GPIO_Mode_IPU);
}


u8 ReadLineTracker(lineTracker linetracker)
{
	return !gpio_read(LineTrackers[linetracker]);
}
