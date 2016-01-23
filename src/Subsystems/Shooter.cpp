#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
		Subsystem("Arm")
{
	shooterLeft = RobotMap::shooterLeft;
	shooterRight = RobotMap::shooterRight;
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::Set(float x)
{
	shooterLeft->Set(x);
	shooterRight->Set(x);
}
