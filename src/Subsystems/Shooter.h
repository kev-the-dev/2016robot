#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem //,PIDOutput
{
private:
	std::shared_ptr<SpeedController> shooterLeft;
	std::shared_ptr<SpeedController> shooterRight;
public:
	Shooter();
	void Set(float x);
	void InitDefaultCommand();
};

#endif
