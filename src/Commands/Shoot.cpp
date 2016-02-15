#include "Shoot.h"

Shoot::Shoot()
{
	shooterPIDSet.reset(new ShooterPIDSet(CommandBase::shooter->SHOOTING_RATE));
	waitForShooter.reset(new WaitForShooter());
	shooterPunchSet.reset(new ShooterPunchSet(DoubleSolenoid::Value::kForward));
	AddSequential(shooterPIDSet.get());
	AddSequential(waitForShooter.get());
	AddSequential(shooterPunchSet.get());
}
