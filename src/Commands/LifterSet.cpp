#include "LifterSet.h"

LifterSet::LifterSet(Lifter::State s)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	state = s;
}

// Called just before this Command runs the first time
void LifterSet::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LifterSet::Execute()
{
	lifter->Set(state);
}

// Make this return true when this Command no longer needs to run execute()
bool LifterSet::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LifterSet::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LifterSet::Interrupted()
{

}
