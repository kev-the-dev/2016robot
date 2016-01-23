#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm() :
		Subsystem("Arm")
{
	std::shared_ptr<SpeedController> armMotor = RobotMap::armMotor;
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Arm::Set(float x)
{
	armMotor->Set(x);
}
