#include "Shoot.h"

Shoot::Shoot()
{
	AddSequential(new ShooterPunchSet(DoubleSolenoid::Value::kForward));
	AddSequential(new WaitCommand(1));
	AddSequential(new ShooterPunchSet(DoubleSolenoid::Value::kReverse));
}
