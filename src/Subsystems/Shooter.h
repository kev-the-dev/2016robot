#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> shooterLeft;
	std::shared_ptr<SpeedController> shooterRight;
public:
	Shooter();
	void Set(float x);
	void InitDefaultCommand();
};

#endif
