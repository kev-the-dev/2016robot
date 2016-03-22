#include "ArmSetBangBang.h"

ArmSetBangBang::ArmSetBangBang(float a)
{
	angle = a;
	Requires(arm.get());
}

// Called just before this Command runs the first time
void ArmSetBangBang::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmSetBangBang::Execute()
{
	float err = Error();
	if (err < 1) arm->Set(-0.2);
	if (err > 1) arm->Set(0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmSetBangBang::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmSetBangBang::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmSetBangBang::Interrupted()
{

}
float ArmSetBangBang::Error()
{
	return angle - arm->GetPot();
}
