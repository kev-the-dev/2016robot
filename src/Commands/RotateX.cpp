#include <Commands/RotateX.h>

float RotateX::p = .04;
float RotateX::i = 0.0005;
float RotateX::d = 0;

RotateX::RotateX(float a) : PIDCommand(p,i,d)
{
	std::cout << "Contructed PID" << std::endl;
	Requires(CommandBase::driveSystem.get());
	driveY = 0;
	angle = a;
	SetSetpoint(angle);
}
RotateX::RotateX(float a, float y) : PIDCommand(p,i,d)
{
	std::cout << "Contructed PID" << std::endl;
	Requires(CommandBase::driveSystem.get());
	driveY = y;
	angle = a;
	SetSetpoint(angle);
}

// Called just before this Command runs the first time
void RotateX::Initialize()
{
	CommandBase::driveSystem->Drive(0,0);
	std::cout << "PID started" << std::endl;
}
// Called repeatedly when this Command is scheduled to run
void RotateX::Execute()
{
	std::cout << "Running PID: P=" << this->GetPIDController()->GetP() << " Setpoint = " << this->GetPIDController()->GetSetpoint();
}

// Make this return true when this Command no longer needs to run execute()
bool RotateX::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RotateX::End()
{
	CommandBase::driveSystem->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateX::Interrupted()
{
	CommandBase::driveSystem->Drive(0,0);
}
double RotateX::ReturnPIDInput()
{
	float angle = CommandBase::driveSystem->GyroAngle();
	std::cout << "Gyro: " << angle << std::endl;
	return angle;
}
void RotateX::UsePIDOutput(double output)
{
	std::cout << "Output: " << output << std::endl;
	CommandBase::driveSystem->Drive(driveY,-output);
}
