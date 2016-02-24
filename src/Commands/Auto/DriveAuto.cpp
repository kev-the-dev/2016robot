#include "DriveAuto.h"

DriveAuto::DriveAuto(double u, double r)
{
	y = u;
	rotation = r;
}

// Called just before this Command runs the first time
void DriveAuto::Initialize()
{
	driveSystem->Drive(y,rotation);
}

// Called repeatedly when this Command is scheduled to run
void DriveAuto::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveAuto::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveAuto::End()
{
	driveSystem->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveAuto::Interrupted()
{
	End();
}
