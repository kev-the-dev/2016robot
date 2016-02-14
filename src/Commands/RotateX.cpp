#include <Commands/RotateX.h>

RotateX::RotateX(float a) : PIDCommand(1,0,0)
{
	driveY = 0;
	SetSetpoint(a);
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

}
double RotateX::ReturnPIDInput()
{
	return CommandBase::driveSystem->GyroAngle();
}
void RotateX::UsePIDOutput(double output)
{
	CommandBase::driveSystem->Drive(driveY,output);
}
