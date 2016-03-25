#include "WaitForArmSimple.h"

WaitForArmSimple::WaitForArmSimple(float x)
{
	val = x;
}

// Called just before this Command runs the first time
void WaitForArmSimple::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitForArmSimple::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForArmSimple::IsFinished()
{
	return std::abs(arm->GetPot() - val) < 1;
}

// Called once after isFinished returns true
void WaitForArmSimple::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForArmSimple::Interrupted()
{

}
