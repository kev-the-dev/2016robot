#include "AutoDriveTest.h"

AutoDriveTest::AutoDriveTest()
{
	Requires(driveSystem.get());

	time = 6;
	speed = 0.25;
	SmartDashboard::PutNumber("Auto Drive Time",time);
	SmartDashboard::PutNumber("Auto Drive Speed",speed);
}

// Called just before this Command runs the first time
void AutoDriveTest::Initialize()
{
	time = SmartDashboard::GetNumber("Auto Drive Time",time);
	speed = SmartDashboard::GetNumber("Auto Drive Speed",speed);
	driveSystem->Drive(speed,0);
	SetTimeout(time);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTest::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTest::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoDriveTest::End()
{
	driveSystem->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTest::Interrupted()
{
	End();
}
