#include "Shooter.h"
#include "../RobotMap.h"

float Shooter::defP = 1;
float Shooter::defI = 0;
float Shooter::defD = 0;
Shooter::Shooter() :
		Subsystem("Arm")
{
	shooterLeft = RobotMap::shooterLeft;
	shooterRight = RobotMap::shooterRight;
	shooterLeftEncoder = RobotMap::shooterLeftEncoder;
	shooterRightEncoder = RobotMap::shooterRightEncoder;

	P = defP;
	I = defI;
	D = defD;

	leftPID.reset(new PIDController(P,I,D,shooterLeftEncoder.get(),shooterLeft.get()));
	leftPID->SetOutputRange(-1,1);
	rightPID.reset(new PIDController(P,I,D,shooterRightEncoder.get(),shooterRight.get()));
	rightPID->SetOutputRange(-1,1);

	PIDenabled = false;
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
	if (IsPIDEnabled()) DisablePID();
	shooterLeft->Set(x);
	shooterRight->Set(x);
}
void Shooter::EnablePID()
{
	leftPID->Enable();
	rightPID->Enable();
	PIDenabled = true;
}
void Shooter::DisablePID()
{
	leftPID->Disable();
	rightPID->Disable();
	PIDenabled = false;
}
bool Shooter::IsPIDEnabled()
{
	return PIDenabled;
}
