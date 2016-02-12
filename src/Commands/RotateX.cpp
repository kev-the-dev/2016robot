#include <Commands/RotateX.h>

RotateX::RotateX(float a) : PIDCommand(1,0,0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	angle = a;
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
double RotateX::PIDGet()
{
	return driveSystem->GyroAngle();
}
void RotateX::PIDWrite(float output)
{
	driveSystem->Drive(0,driveY);
}
