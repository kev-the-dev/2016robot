#include "ShooterWithJoystick.h"

ShooterWithJoystick::ShooterWithJoystick()
{
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void ShooterWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterWithJoystick::Execute()
{
	shooter->Set(oi->GetOpZ());
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterWithJoystick::End()
{
	shooter->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterWithJoystick::Interrupted()
{
	shooter->Set(0);
}
