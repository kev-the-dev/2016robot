#include "LowBarForward.h"

#include "Commands/ArmSet.h"
#include "Commands/Auto/DriveAuto.h"

LowBarForward::LowBarForward()
{
	AddSequential(new DoForTime(std::unique_ptr<Command>(new ArmSet(-0.3)),0.5));
	AddSequential(new ArmSet(0));
	AddSequential(new DoForTime(std::unique_ptr<Command>(new RotateX(0,-0.5)),4));
	AddSequential(new DriveAuto(0,0));
}
