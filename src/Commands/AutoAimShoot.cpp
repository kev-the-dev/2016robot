#include "AutoAimShoot.h"

double AutoAimShoot::angle = 45;

AutoAimShoot::AutoAimShoot()
{
	armGoTo.reset(new ArmGoToNoPID(angle));
	spinUpShooter.reset(new ShooterSet(1));
	turnOffShooter.reset(new ShooterSet(0));
	shoot.reset(new DoForTime(std::unique_ptr<Command>(new ShooterPunchSet(DoubleSolenoid::kForward)),0.5 ));
	shootIn.reset(new ShooterPunchSet(DoubleSolenoid::kReverse));

	AddParallel(spinUpShooter.get());
	AddSequential(armGoTo.get());
	AddSequential(shoot.get());
	AddParallel(shootIn.get());
	AddParallel(turnOffShooter.get());

}
