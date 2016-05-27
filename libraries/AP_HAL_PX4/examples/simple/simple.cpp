/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

/*
  simple hello world sketch
  Andrew Tridgell September 2011
*/

#include <AP_HAL/AP_HAL.h>

const AP_HAL::HAL& hal = AP_HAL::get_HAL();
int i = 0;
void setup() 
{
	hal.console->println("hello world,PGP");
}

void loop()
{
	hal.scheduler->delay(1000);
	++i;
	hal.console->println("*");
	hal.console->printf("pgp:---%d\n",i);
}

AP_HAL_MAIN();
