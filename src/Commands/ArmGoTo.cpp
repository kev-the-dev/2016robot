#include "ArmGoTo.h"

ArmGoTo::ArmGoTo(double a)
{
	angle = a;
}

// Called just before this Command runs the first time
void ArmGoTo::Initialize()
{
	arm->Enable();
	arm->SetSetpoint(angle);
}

// Called repeatedly when this Command is scheduled to run
void ArmGoTo::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ArmGoTo::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ArmGoTo::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmGoTo::Interrupted()
{

}
