#include "LowBarScore.h"

#include "Commands/Auto/LowBarForward.h"
#include "Commands/ArmGoToNoPID.h"
#include "Commands/ShooterPunchSet.h"
#include "Commands/ShooterSet.h"

double LowBarScore::turnAngle = 30;
double LowBarScore::angle = 45;

LowBarScore::LowBarScore() : CommandGroup("LowBarScore")
{
	AddSequential(new LowBarForward());
	//AddSequential(new DoForTime(std::unique_ptr<Command>(new RotateX(turnAngle),4)));
	AddParallel(new ShooterSet(1));
	AddSequential(new ArmGoToNoPID(angle));
	AddSequential(new ShooterPunchSet(DoubleSolenoid::kForward));
	AddSequential(new WaitCommand(1));
	AddParallel(new ShooterPunchSet(DoubleSolenoid::kReverse));
	AddParallel(new ShooterSet(0));
}
