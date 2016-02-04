#include "SmartDashboardInfo.h"

SmartDashboardInfo::SmartDashboardInfo()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	SmartDashboard::PutNumber("Pot",0);
}

// Called just before this Command runs the first time
void SmartDashboardInfo::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SmartDashboardInfo::Execute()
{
	SmartDashboard::PutNumber("Pot",arm->GetPot());
}

// Make this return true when this Command no longer needs to run execute()
bool SmartDashboardInfo::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SmartDashboardInfo::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SmartDashboardInfo::Interrupted()
{

}
