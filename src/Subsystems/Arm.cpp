#include "Arm.h"
#include "../RobotMap.h"

float Arm::defP = 0;
float Arm::defI = 0;
float Arm::defD = 0;

Arm::Arm() : Subsystem("Arm")
{
	armMotor = RobotMap::armMotor;
	armPot = RobotMap::armPot;

	P = defP;
	I = defI;
	D = defD;
	armPID.reset(new PIDController(P,I,D,armPot.get(),armMotor.get()));
	armPID->SetOutputRange(-1,1);
	PIDenabled = false;
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
void Arm::EnablePID()
{
	armPID->Enable();
	PIDenabled = true;
}
void Arm::DisablePID()
{
	armPID->Disable();
	PIDenabled = false;
}
bool Arm::IsPIDEnabled()
{
	return PIDenabled;
}
void Arm::SetSetpoint(double x)
{
	armPID->SetSetpoint(x);
}
