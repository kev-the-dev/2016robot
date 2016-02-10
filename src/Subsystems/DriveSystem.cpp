#include "DriveSystem.h"
#include "../RobotMap.h"

DriveSystem::DriveSystem() :
		Subsystem("DriveSystem")
{
	drive = RobotMap::drive;
	gyro = RobotMap::gyro;
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
	drive->ArcadeDrive(y,rotation);
}
float DriveSystem::GyroAngle()
{
	return gyro->GetAngle();
}
