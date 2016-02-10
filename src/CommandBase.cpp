#include "CommandBase.h"
#include "Commands/Scheduler.h"

std::unique_ptr<DriveSystem> CommandBase::driveSystem;
std::unique_ptr<Arm> CommandBase::arm;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<Shooter> CommandBase::shooter;

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
	RobotMap::init();

	// Create a single static instance of all of your subsystems
	driveSystem.reset(new DriveSystem());
	arm.reset(new Arm());
	shooter.reset(new Shooter());

	//Setup OI
	oi.reset(new OI());
}
