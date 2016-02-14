#include "WaitForArm.h"

WaitForArm::WaitForArm()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

float WaitForArm::maxError = 1;

// Called just before this Command runs the first time
void WaitForArm::Initialize()
{
	if (!arm->IsPIDEnabled()) Cancel();
}

// Called repeatedly when this Command is scheduled to run
void WaitForArm::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForArm::IsFinished()
{
	return (std::abs(arm->GetPIDError()) < maxError);
}

// Called once after isFinished returns true
void WaitForArm::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForArm::Interrupted()
{

}
