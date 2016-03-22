#ifndef AutoAimShoot_H
#define AutoAimShoot_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

#include "Commands/Arm/ArmGoToNoPID.h"
#include "Commands/Shooter/ShooterSet.h"
#include "ShooterPunchSet.h"

class AutoAimShoot: public CommandGroup
{
private:
	static double angle;
public:
	AutoAimShoot();
};

#endif
