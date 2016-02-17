#include "Arm.h"
#include "../RobotMap.h"

float Arm::P = 1;
float Arm::I = 0;
float Arm::D = 0;

float Arm::percentageTolerance = 5;

double loweredPot = 0;
double shootingPot = 45;

Arm::Arm() : Subsystem("Arm")
{
	armMotor = RobotMap::armMotor;
	armPot = RobotMap::armPot;

	armPID.reset(new PIDController(P,I,D,armPot.get(),armMotor.get()));
	armPID->SetOutputRange(-1,1);
	armPID->SetPercentTolerance(percentageTolerance);

	LiveWindow::GetInstance()->AddActuator("Arm","Arm PID",armPID.get());
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
}
void Arm::DisablePID()
{
	armPID->Disable();
}
bool Arm::IsPIDEnabled()
{
	return armPID->IsEnabled();
}
void Arm::SetSetpoint(double x)
{
	armPID->SetSetpoint(x);
}
double Arm::GetPot()
{
	return armPot->Get();
}
bool Arm::OnTarget()
{
	return armPID->OnTarget();
}
