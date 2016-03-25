#include "RotateX.h"

double RotateX::p = .04;
double RotateX::i = 0.0005;
double RotateX::d = 0;

RotateX::RotateX(float a) : PIDCommand("RotateX",p,i,d)
{
	Requires(CommandBase::driveSystem.get());
	driveY = 0;
	angle = a;
	SetSetpoint(angle);
}
RotateX::RotateX(float a, float y) : PIDCommand("RotateX",p,i,d)
{
	Requires(CommandBase::driveSystem.get());
	driveY = y;
	angle = a;
	SetSetpoint(angle);
}

// Called just before this Command runs the first time
void RotateX::Initialize()
{

}
// Called repeatedly when this Command is scheduled to run
void RotateX::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool RotateX::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RotateX::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateX::Interrupted()
{
	End();
}
double RotateX::ReturnPIDInput()
{
	return CommandBase::driveSystem->GyroAngle();
}
void RotateX::UsePIDOutput(double output)
{
	CommandBase::driveSystem->Drive(driveY,-output);
}
