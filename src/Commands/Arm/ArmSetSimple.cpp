#include "ArmSetSimple.h"

#include "Commands/Arm/ArmSet.h"
#include "Commands/WaitForArmSimple.h"

ArmSetSimple::ArmSetSimple(float speed, float val)
{
	AddSequential(new ArmSet(speed));
	AddSequential(new WaitForArmSimple(val));
}
