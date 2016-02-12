#include "Lifter.h"
#include "../RobotMap.h"

Lifter::Lifter() :
		Subsystem("ExampleSubsystem")
{
	pistonForward = RobotMap::lifterPistonForward;
	pistonReverse = RobotMap::lifterPistonReverse;
	bimbaSwitch = RobotMap::lifterSwitch;
	state = kOff;
}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	pistonForward = RobotMap::lifterPistonForward;
	pistonReverse = RobotMap::lifterPistonReverse;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
bool Lifter::Switch()
{
	return !bimbaSwitch->Get();
}
void Lifter::Off()
{
	pistonForward->Set(0);
	pistonReverse->Set(0);
}
void Lifter::Forward()
{
	pistonForward->Set(1);
	pistonReverse->Set(0);
}
void Lifter::Reverse()
{
	pistonForward->Set(0);
	pistonReverse->Set(1);
}
void Lifter::On()
{
	pistonForward->Set(1);
	pistonReverse->Set(1);
}
void Lifter::Set(Lifter::State s)
{
	state = s;
	switch (s)
	{
	case kOn:
		On();
		break;
	case kOff:
		Off();
		break;
	case kForward:
		Forward();
		break;
	case kReverse:
		Reverse();
		break;
	}
}
