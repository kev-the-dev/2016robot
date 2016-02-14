#include "WaitForShooter.h"

WaitForShooter::WaitForShooter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
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
	return (std::abs(shooter->LeftError()) < maxError) && (std::abs(shooter->RightError()) < maxError);
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
