#include "ArmSet.h"

ArmSet::ArmSet(double x)
{
	Requires(arm.get());
	set_val = x;
}

// Called just before this Command runs the first time
void ArmSet::Initialize()
{
	arm->DisablePID();
	arm->Set(set_val);
}

// Called repeatedly when this Command is scheduled to run
void ArmSet::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ArmSet::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ArmSet::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmSet::Interrupted()
{

}
