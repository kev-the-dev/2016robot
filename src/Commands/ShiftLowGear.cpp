#include "ShiftLowGear.h"

ShiftLowGear::ShiftLowGear()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShiftLowGear::Initialize()
{
	driveSystem->SetLowGear();
}

// Called repeatedly when this Command is scheduled to run
void ShiftLowGear::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShiftLowGear::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShiftLowGear::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftLowGear::Interrupted()
{

}
