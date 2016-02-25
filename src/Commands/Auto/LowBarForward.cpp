#include "LowBarForward.h"

#include "Commands/ArmSet.h"
#include "Commands/Auto/DriveAuto.h"

LowBarForward::LowBarForward()
{
	AddSequential(new ArmSet(-0.3));
	AddSequential(new WaitCommand(0.5));
	AddSequential(new ArmSet(0));
	AddSequential(new RotateX(0,-0.5));
	AddSequential(new WaitCommand(4));
	AddSequential(new DriveAuto(0,0));
}
