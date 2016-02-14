#include <Commands/RotateX.h>

RotateX::RotateX(float a) : PIDCommand(1,0,0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	angle = a;
	driveY = 0;
	p = .0014;
	i = 0;
	d = 0;
	SetSetpoint(a);
}

// Called just before this Command runs the first time
void RotateX::Initialize()
{
	p = SmartDashboard::GetNumber("p",p);
	i = SmartDashboard::GetNumber("i",i);
	d = SmartDashboard::GetNumber("d",d);
	angle = SmartDashboard::GetNumber("Angle",angle);
	SetSetpoint(angle);
	GetPIDController()->SetPID(p,i,d);
}
// Called repeatedly when this Command is scheduled to run
void RotateX::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool RotateX::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RotateX::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateX::Interrupted()
{

}
double RotateX::ReturnPIDInput()
{
	return CommandBase::driveSystem->GyroAngle();
}
void RotateX::UsePIDOutput(double output)
{
	CommandBase::driveSystem->Drive(driveY,output);
}
