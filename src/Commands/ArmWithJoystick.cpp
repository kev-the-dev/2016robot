#include "ArmWithJoystick.h"

ArmWithJoystick::ArmWithJoystick()
{
	Requires(arm.get());
}

// Called just before this Command runs the first time
void ArmWithJoystick::Initialize()
{
	arm->DisablePID();
	arm->Set(0);
}

// Called repeatedly when this Command is scheduled to run
void ArmWithJoystick::Execute()
{
	arm->Set(oi->GetOpY());
}

// Make this return true when this Command no longer needs to run execute()
bool ArmWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmWithJoystick::End()
{
	arm->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmWithJoystick::Interrupted()
{
	End();
}
