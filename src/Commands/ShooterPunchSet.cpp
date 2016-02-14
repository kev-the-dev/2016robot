#include "ShooterPunchSet.h"

ShooterPunchSet::ShooterPunchSet(DoubleSolenoid::Value v)
{
	state = v;
}

// Called just before this Command runs the first time
void ShooterPunchSet::Initialize()
{
	shooterPunch->Set(state);
}

// Called repeatedly when this Command is scheduled to run
void ShooterPunchSet::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterPunchSet::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShooterPunchSet::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterPunchSet::Interrupted()
{

}
