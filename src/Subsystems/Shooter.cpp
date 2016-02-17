#include "Shooter.h"
#include "../RobotMap.h"

float Shooter::P = 1;
float Shooter::I = 0;
float Shooter::D = 0;

float Shooter::percentageTolerance = 5;

Shooter::Shooter() :
		Subsystem("Arm")
{
	shooterLeft = RobotMap::shooterLeft;
	shooterRight = RobotMap::shooterRight;
	shooterLeftEncoder = RobotMap::shooterLeftEncoder;
	shooterRightEncoder = RobotMap::shooterRightEncoder;

	//Ensure encoder uses rate, not distance
	shooterLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);
	shooterRightEncoder->SetPIDSourceType(PIDSourceType::kRate);

	leftPID.reset(new PIDController(P,I,D,shooterLeftEncoder.get(),shooterLeft.get()));
	rightPID.reset(new PIDController(P,I,D,shooterRightEncoder.get(),shooterRight.get()));

	leftPID->SetOutputRange(-1,1);
	rightPID->SetOutputRange(-1,1);

	leftPID->SetPercentTolerance(percentageTolerance);
	rightPID->SetPercentTolerance(percentageTolerance);

	PIDenabled = false;

	onePID.reset(new PIDController(P,I,D,shooterLeftEncoder.get(),this));
	onePID->SetOutputRange(-1,1);
	onePID->SetPercentTolerance(percentageTolerance);

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
	shooterLeft->Set(-x);
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
double Shooter::LeftRate()
{
	return shooterLeftEncoder->GetRate();
}
double Shooter::RightRate()
{
	return shooterRightEncoder->GetRate();
}
void Shooter::PIDSet(float rate)
{
	leftPID->SetSetpoint(rate);
	rightPID->SetSetpoint(rate);
}
bool Shooter::LeftOnTarget()
{
	return leftPID->GetError();
}
bool Shooter::RightOnTarget()
{
	return rightPID->OnTarget();
}
void Shooter::PIDWrite(float output)
{
	Set(output);
}
