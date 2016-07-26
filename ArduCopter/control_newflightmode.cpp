///-*- tab-width:4;mode:C++;c-basic-offset: 4; indent-tabs-mode;nil -*-
#include "Copter.h"

/*
 *control_newflightmode.cpp -init and run calls for new flight mode
 */
 //newflightmode_init -initialise flight mode
 bool Copter::newflightmode_init(bool ignore_checks)
 {
 	//do any required initialisation of the flight mode here
 	//this code wlill be called whenever the operator switch into this mode
 	hal.console->printf("entry newflightmode\n");
 	//return the true initialisation is successful,false if it fails
 	//if false is returned here the vehicle will remain the previous flight mode
 	return true;	
 }

 //newflightmode_run - runs the main controller
 //will be called at 100hz or more
 void Copter::newflightmode_run()
 {
 	static uint32_t counter = 0;
 	//if not armed or throttle at zero, set throttle to zero and exit immediately
 	/*if(!motors.armed() || g.rc_3.get_control_in() <= 0){
 		attitude_control.relax_bf_rate_controller();
 		attitude_control.set_yaw_target_to_current_heading();
 		attitude_control.set_throttle_out(0, false, 0);
 		return;
 	}*/
 	++counter;
 	hal.console->printf("newflightmode_run the %u\n", counter);
 	hal.scheduler->delay(1000);
 	// convert pilot input into desired vehicle angles or rotation rates
 	//	g.rc_1.control_in : pilots roll input in the range -4500 ~ 4500
 	//	g.rc_2.control_in : pilots pitch input in the range -4500 ~ 4500
 	// 	g.rc_3.control_in : pilot's throttle input in the range 0 ~ 1000
 	//	g.rc_4.control_in : pilots yaw input in the range -4500 ~ 4500

 	//call one of attitude controll's attitude control functions like
 	//	attitude_control.angle_ef_roll_pitch_rate_yaw(roll angle, pitch angle, yaw rate);
	
	//call position controller's z-axis controller or simply pass through throttle
	//	attitude_control.set_throttle(desired throttle, true);
 }