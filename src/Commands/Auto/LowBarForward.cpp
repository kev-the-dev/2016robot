#include "LowBarForward.h"

#include "Commands/ArmSet.h"
#include "Commands/Auto/DriveAuto.h"
#include "Commands/Auto/LowArmAuto.h"
#include "Commands/ArmSetBangBang.h"
#include "Commands/WaitForArmSimple.h"

LowBarForward::LowBarForward() : CommandGroup("LowBarForward")
{
	//AddParallel(new RotateX(0,-0.75));
	AddSequential(new DriveAuto(-0.75,0));
	AddSequential(new WaitCommand(0.25));
	AddSequential(new DriveAuto(0,0));

	//Arm Stuff
	//AddSequential(new LowArmAuto());
	AddParallel(new ArmSetBangBang(0));
	AddSequential(new WaitForArmSimple(0));
	AddSequential(new DriveAuto(-0.75,0));
	AddSequential(new WaitCommand(3.75));
	AddSequential(new DriveAuto(0,0));
	AddSequential(new ArmSet(0));
}
