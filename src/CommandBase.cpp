#include "CommandBase.h"
#include "Commands/Scheduler.h"

DriveSystem* CommandBase::driveSystem = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	driveSystem = new DriveSystem();

	//Setup OI
	oi = new OI();
}
