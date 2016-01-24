#include "DoForTime.h"

//Note: DoForTime deletes c when time is finished. Should be constructed with new command pointer
DoForTime::DoForTime(Command* c,double t)
{
	time = t;
	command.reset(c);
}

// Called just before this Command runs the first time
void DoForTime::Initialize()
{
	SetTimeout(time);
	command->Start();
}

// Called repeatedly when this Command is scheduled to run
void DoForTime::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DoForTime::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void DoForTime::End()
{
	command->Cancel();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoForTime::Interrupted()
{
	End();
}
