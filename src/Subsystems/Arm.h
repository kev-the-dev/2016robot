#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public PIDSubsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> armMotor;
	std::shared_ptr<Potentiometer> armPot;

	static double p;
	static double i;
	static double d;

	bool isOn;
public:
	Arm();
	void Set(double x);
	void InitDefaultCommand();

	double ReturnPIDInput();
	void UsePIDOutput(double output);

	void enable();
	void disable();
	bool isEnabled();
};

#endif
