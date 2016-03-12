#include "LowArmAuto.h"

#include "Commands/ArmSet.h"
#include "Commands/WaitForArmSimple.h"

LowArmAuto::LowArmAuto()
{
	AddSequential(new ArmSet(-0.2));
	AddSequential(new WaitForArmSimple(0));
	AddSequential(new ArmSet(0));
}
