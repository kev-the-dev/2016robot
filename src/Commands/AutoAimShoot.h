#ifndef AutoAimShoot_H
#define AutoAimShoot_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

#include "ArmGoToNoPID.h"
#include "ShooterSet.h"
#include "ShooterPunchSet.h"
#include "Auto/DoForTime.h"

class AutoAimShoot: public CommandGroup
{
private:
	std::unique_ptr<Command> armGoTo;
	std::unique_ptr<Command> spinUpShooter;
	std::unique_ptr<Command> turnOffShooter;
	std::unique_ptr<Command> shoot;
	std::unique_ptr<Command> shootIn;

	static double angle;
public:
	AutoAimShoot();
};

#endif
