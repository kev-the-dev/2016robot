#include "Shooter.h"
#include "../RobotMap.h"

//float Shooter::P = 1;
//float Shooter::I = 0;
//float Shooter::D = 0;
//
//float Shooter::percentageTolerance = 5;

Shooter::Shooter() :
		Subsystem("Arm")
{
	shooterLeft = RobotMap::shooterLeft;
	shooterRight = RobotMap::shooterRight;
}

void Shooter::InitDefaultCommand()
{

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::Set(float x)
{
	shooterLeft->Set(-x);
	shooterRight->Set(x);
}
