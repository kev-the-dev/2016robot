#include "DoForTime.h"

//Note: DoForTime deletes c when time is finished. Should be constructed with new command pointer
DoForTime::DoForTime(std::unique_ptr<Command> c,double t) : WaitCommand(t)
{
	command = std::move(c);
}

// Called just before this Command runs the first time
void DoForTime::Initialize()
{
	command->Start();
}
// Called once after isFinished returns true
void DoForTime::End()
{
	std::cout << "DoForTime Ended" << std::endl;
	command->Cancel();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoForTime::Interrupted()
{
	End();
}
