#include "SpyBoxAuto.h"

#include "Commands/Arm/ArmGoTo.h"
#include "Commands/Shooter/ShooterSet.h"
#include "Commands/Punch/ShooterPunchSet.h"
#include "Commands/Arm/WaitForArm.h"

double SpyBoxAuto::angle = 45;

SpyBoxAuto::SpyBoxAuto() : CommandGroup("SpyBoxAuto")
{
	AddSequential(new ArmGoTo(angle));
	AddParallel(new ShooterSet(1));
	AddSequential(new WaitForArm());
	AddSequential(new ShooterPunchSet(DoubleSolenoid::kForward));
	AddSequential(new WaitCommand(1));
	AddParallel(new ShooterPunchSet(DoubleSolenoid::kReverse));
	AddParallel(new ShooterSet(0));
}
