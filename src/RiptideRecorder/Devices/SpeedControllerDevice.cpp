/*
 * SpeedControllerDevice.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: kma1660
 */

#include "SpeedControllerDevice.h"

SpeedControllerDevice::SpeedControllerDevice(std::string x,SpeedController* c) : Device(x){
	ctrl = c;
}
float SpeedControllerDevice::restrict(float x)
{
	if (x > 1) return 1;
	else if (x < -1) return -1;
	return x;
}
float SpeedControllerDevice::get()
{
	return restrict(ctrl->Get());
}
void SpeedControllerDevice::set(float x) {
	ctrl->Set(restrict(x));
}
