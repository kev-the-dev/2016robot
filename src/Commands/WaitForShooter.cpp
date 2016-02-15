#include "WaitForShooter.h"

WaitForShooter::WaitForShooter()
{
	Requires(shooter.get());
}

float WaitForShooter::maxError = 1;

// Called just before this Command runs the first time
void WaitForShooter::Initialize()
{
	if (!shooter->IsPIDEnabled()) Cancel();
}

// Called repeatedly when this Command is scheduled to run
void WaitForShooter::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForShooter::IsFinished()
{
	return shooter->LeftOnTarget() && shooter->RightOnTarget();
}

// Called once after isFinished returns true
void WaitForShooter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForShooter::Interrupted()
{

}
