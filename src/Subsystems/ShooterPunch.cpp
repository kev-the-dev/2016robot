#include "ShooterPunch.h"
#include "../RobotMap.h"

ShooterPunch::ShooterPunch() :
		Subsystem("ExampleSubsystem")
{
	state = DoubleSolenoid::Value::kOff;
}

void ShooterPunch::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterPunch::Set(DoubleSolenoid::Value v)
{
	punch->Set(v);
	state = v;
}
DoubleSolenoid::Value ShooterPunch::GetState()
{
	return state;
}
