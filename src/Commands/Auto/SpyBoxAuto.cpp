#include "SpyBoxAuto.h"

#include "Commands/ArmGoTo.h"
#include "Commands/ShooterSet.h"
#include "Commands/ShooterPunchSet.h"
#include "Commands/WaitForArm.h"

double SpyBoxAuto::angle = 45;

SpyBoxAuto::SpyBoxAuto()
{
	AddSequential(new ArmGoTo(angle));
	AddParallel(new ShooterSet(1));
	AddSequential(new WaitForArm());
	AddSequential(new ShooterPunchSet(DoubleSolenoid::kForward));
	AddSequential(new WaitCommand(1));
	AddParallel(new ShooterPunchSet(DoubleSolenoid::kReverse));
	AddParallel(new ShooterSet(0));
}
