#include "Commands/DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveSystem.get());
	kP =  0;
	kI = 0;
	angle = 0;
	stackSize = 10;
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize()
{
	driveSystem->Drive(0,0);
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute()
{
	this->kP = SmartDashboard::GetNumber("p",0);
	this->kP = SmartDashboard::GetNumber("i",0);
	this->stackSize = SmartDashboard::GetNumber("Stack Size",0);
	this->angle = SmartDashboard::GetNumber("Angle",0);
	if (oi->stickLeft->GetRawButton(2)) {
		driveSystem->gyro->Reset();
	}
	double u = 0;
	if (oi->GetPIDButton()) {
		float error = angle - driveSystem->GyroAngle();
		errors.push_back(error);
		if (errors.size() > stackSize) {
			errors.pop_front();
		}
		u = -(kP*error + std::accumulate(errors.begin(), errors.end(), 0));
	}
	else {
		u = oi->GetDriveRotation();
		errors.clear();
	}

	SmartDashboard::PutNumber("u",u);
	driveSystem->Drive(oi->GetDriveY(),u);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoysticks::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoysticks::End()
{
	Initialize();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted()
{
	Initialize();
}
