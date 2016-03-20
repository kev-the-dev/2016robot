#include "AutoArmTest.h"

AutoArmTest::AutoArmTest()
{
	Requires(arm.get());
	x = 0.3;
	time = 0.5;
	SmartDashboard::PutNumber("Auto Arm Test Speed",x);
	SmartDashboard::PutNumber("Arm Arm Test Time",time);
	isGoing = false;
}

// Called just before this Command runs the first time
void AutoArmTest::Initialize()
{
	x = SmartDashboard::GetNumber("Auto Arm Test Speed",x);
	time = SmartDashboard::GetNumber("Auto Arm Test Speed",time);
	arm->Set(x);
	SetTimeout(time);
}

// Called repeatedly when this Command is scheduled to run
void AutoArmTest::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutoArmTest::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoArmTest::End()
{
	arm->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoArmTest::Interrupted()
{
	End();
}
