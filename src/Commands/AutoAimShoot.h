#ifndef AutoAimShoot_H
#define AutoAimShoot_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

#include "ArmGoToNoPID.h"
#include "ShooterSet.h"
#include "ShooterPunchSet.h"

class AutoAimShoot: public CommandGroup
{
private:
	static double angle;
public:
	AutoAimShoot();
};

#endif
