#include "AutoAimShoot.h"

double AutoAimShoot::angle = 45;

AutoAimShoot::AutoAimShoot()
{
	AddParallel(new ShooterSet(1));
	AddSequential(new ArmGoToNoPID(angle));
	AddSequential(new ShooterPunchSet(DoubleSolenoid::kForward));
	AddSequential(new WaitCommand(0.5));
	AddParallel(new ShooterPunchSet(DoubleSolenoid::kReverse));
	AddParallel(new ShooterSet(0));

}
