#include "ShooterPIDSet.h"

ShooterPIDSet::ShooterPIDSet(double r)
{
	Requires(shooter.get());
	rate = r;
}

// Called just before this Command runs the first time
void ShooterPIDSet::Initialize()
{
	shooter->EnablePID();
	shooter->PIDSet(rate);
}

// Called repeatedly when this Command is scheduled to run
void ShooterPIDSet::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterPIDSet::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShooterPIDSet::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterPIDSet::Interrupted()
{

}
