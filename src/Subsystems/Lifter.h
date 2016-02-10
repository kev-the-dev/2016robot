#ifndef Lifter_H
#define Lifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
private:
	std::shared_ptr<DoubleSolenoid> piston;
	std::shared_ptr<DigitalInput> bimbaSwitch;
	DoubleSolenoid::Value state;
public:
	Lifter();
	bool Switch();
	void Off();
	void Extend();
	void Retract();
	DoubleSolenoid::Value State();
	void InitDefaultCommand();
};

#endif
