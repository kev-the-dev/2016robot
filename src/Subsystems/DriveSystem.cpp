#include "DriveSystem.h"
#include "../RobotMap.h"

DriveSystem::DriveSystem() :
		Subsystem("DriveSystem")
{
	drive.reset(new RobotDrive(RobotMap::leftOne,RobotMap::leftTwo,RobotMap::rightOne,RobotMap::rightTwo));
	leftTransmission = RobotMap::leftTransmission;
	rightTransmission = RobotMap::rightTransmission;
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
void DriveSystem::SetLowGear()
{
	leftTransmission->Set(DoubleSolenoid::kReverse);
	rightTransmission->Set(DoubleSolenoid::kReverse);
}
void DriveSystem::SetHighGear()
{
	leftTransmission->Set(DoubleSolenoid::kForward);
	rightTransmission->Set(DoubleSolenoid::kForward);
}
