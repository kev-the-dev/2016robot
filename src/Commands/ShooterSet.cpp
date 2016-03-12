#include "ShooterSet.h"

ShooterSet::ShooterSet(double s)
{
	Requires(shooter.get());
	speed = s;
}

// Called just before this Command runs the first time
void ShooterSet::Initialize()
{
	shooter->DisablePID();
	shooter->Set(speed);
	RobotMap::compressor->Stop();
}

// Called repeatedly when this Command is scheduled to run
void ShooterSet::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSet::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShooterSet::End()
{
	RobotMap::compressor->Start();
//	shooter->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterSet::Interrupted()
{
	End();
}
