#include "DriveSystem.h"
#include "../RobotMap.h"

DriveSystem::DriveSystem() :
		Subsystem("DriveSystem")
{
	drive = RobotMap::drive;
	gyro = RobotMap::gyro;
	encoderLeft = RobotMap::driveEncoderLeft;
	encoderRight = RobotMap::driveEncoderRight;
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
double DriveSystem::Distance()
{
	return (encoderLeft->GetDistance() + encoderRight->GetDistance()) / 2;
}
double DriveSystem::Rate()
{
	return (encoderLeft->GetRate() + encoderRight->GetRate()) / 2;
}
