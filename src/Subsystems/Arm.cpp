#include "Arm.h"
#include "../RobotMap.h"

double Arm::p = 0;
double Arm::i = 0;
double Arm::d = 0;

Arm::Arm() : PIDSubsystem("Arm",p,i,d)
{
	armMotor = RobotMap::armMotor;
	armPot = RobotMap::armPot;

	SetInputRange(-1,1);
	SetOutputRange(-1,1);

	isOn = false;
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Arm::Set(double x)
{
	armMotor->Set(x);
}
double Arm::ReturnPIDInput()
{
	return armPot->Get();
}
void Arm::UsePIDOutput(double output)
{
	Set(output);
}
void Arm::disable()
{
	isOn = false;
	Disable();
}
void Arm::enable()
{
	isOn = true;
	Enable();
}
bool Arm::isEnabled()
{
	return isOn;
}
