#include "DriveTransmission.h"
#include "../RobotMap.h"

DriveTransmission::DriveTransmission() :
		Subsystem("ExampleSubsystem")
{
	leftTransmission = RobotMap::leftTransmission;
	rightTransmission = RobotMap::rightTransmission;
}

void DriveTransmission::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTransmission::SetLowGear()
{
	leftTransmission->Set(DoubleSolenoid::kReverse);
	rightTransmission->Set(DoubleSolenoid::kReverse);
}
void DriveTransmission::SetHighGear()
{
	leftTransmission->Set(DoubleSolenoid::kForward);
	rightTransmission->Set(DoubleSolenoid::kForward);
}
