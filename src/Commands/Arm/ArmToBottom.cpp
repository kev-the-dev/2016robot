#include "ArmToBottom.h"

ArmToBottom::ArmToBottom()
{
	Requires(arm.get());
}

// Called just before this Command runs the first time
void ArmToBottom::Initialize()
{
	arm->DisablePID();
	arm->Set(-0.2);
	SetTimeout(3);
}

// Called repeatedly when this Command is scheduled to run
void ArmToBottom::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ArmToBottom::IsFinished()
{
	return arm->BottomSwitch() || IsTimedOut();
}

// Called once after isFinished returns true
void ArmToBottom::End()
{
	arm->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmToBottom::Interrupted()
{
	End();
}
