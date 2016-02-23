#include "Shoot.h"

Shoot::Shoot()
{
	punchForward.reset(new ShooterPunchSet(DoubleSolenoid::Value::kForward));
	punchReverse.reset(new ShooterPunchSet(DoubleSolenoid::Value::kReverse));
	doForTime.reset(new DoForTime(std::move(punchForward),1));
	AddSequential(doForTime.get());
	AddSequential(punchReverse.get());
}
