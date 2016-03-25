#ifndef Lifter_H
#define Lifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
public:
	enum State {
		kOn,
		kOff,
		kForward,
		kReverse
	};
private:
	std::shared_ptr<Solenoid> pistonForward;
	std::shared_ptr<Solenoid> pistonReverse;
	std::shared_ptr<DigitalInput> bimbaSwitch;
	void On();
	void Off();
	void Forward();
	void Reverse();
	State state;
public:
	Lifter();
	bool Switch();
	void Set(State s);
	void InitDefaultCommand();
};

#endif
