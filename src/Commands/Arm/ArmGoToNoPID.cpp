#include "ArmGoToNoPID.h"

double ArmGoToNoPID::defSpeed = 0.6;

//Goes to a point by driving motor till pot says good;
//Only works when raising arm (current angele < a)
ArmGoToNoPID::ArmGoToNoPID(double a)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	angle = a;
	speed = defSpeed;
	Init();
}
ArmGoToNoPID::ArmGoToNoPID(double a,double s)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	angle = a;
	speed = s;
	Init();
}

void ArmGoToNoPID::Init()
{
	Requires(arm.get());
}

// Called just before this Command runs the first time
void ArmGoToNoPID::Initialize()
{
	arm->DisablePID();
	arm->Set(speed);
}

// Called repeatedly when this Command is scheduled to run
void ArmGoToNoPID::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ArmGoToNoPID::IsFinished()
{
	return arm->GetPot() >= angle;
}

// Called once after isFinished returns true
void ArmGoToNoPID::End()
{
	arm->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmGoToNoPID::Interrupted()
{
	End();
}
