#include "Lifter.h"
#include "../RobotMap.h"

Lifter::Lifter() :
		Subsystem("ExampleSubsystem")
{
	piston = RobotMap::lifterPiston;
	bimbaSwitch = RobotMap::lifterSwitch;
}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	state = DoubleSolenoid::Value::kOff;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
bool Lifter::Switch()
{
	return bimbaSwitch->Get();
}
void Lifter::Off()
{
	piston->Set(DoubleSolenoid::Value::kOff);
	state = DoubleSolenoid::Value::kOff;
}
void Lifter::Extend()
{
	piston->Set(DoubleSolenoid::Value::kForward);
	state = DoubleSolenoid::Value::kForward;
}
void Lifter::Retract()
{
	piston->Set(DoubleSolenoid::Value::kReverse);
	state = DoubleSolenoid::Value::kReverse;
}
