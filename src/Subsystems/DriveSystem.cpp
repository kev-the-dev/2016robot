#include "DriveSystem.h"
#include "../RobotMap.h"

DriveSystem::DriveSystem() :
		Subsystem("DriveSystem")
{

}

void DriveSystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveSystem::Drive(float y, float rotation)
{

}
