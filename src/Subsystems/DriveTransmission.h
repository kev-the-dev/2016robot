#ifndef DriveTransmission_H
#define DriveTransmission_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTransmission: public Subsystem
{
private:
	std::shared_ptr<DoubleSolenoid> leftTransmission;
	std::shared_ptr<DoubleSolenoid> rightTransmission;
public:
	DriveTransmission();
	void InitDefaultCommand();
	void SetHighGear();
	void SetLowGear();
};

#endif
