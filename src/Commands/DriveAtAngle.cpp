#include "DriveAtAngle.h"

DriveAtAngle::DriveAtAngle() : PIDCommand(1,0,0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveAtAngle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveAtAngle::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveAtAngle::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveAtAngle::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveAtAngle::Interrupted()
{

}
double DriveAtAngle::PIDGet()
{
	return driveSystem->GyroAngle();
}
void DriveAtAngle::PIDWrite(float output)
{
	driveSystem->Drive(0,output);
}
