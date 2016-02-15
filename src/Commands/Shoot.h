#ifndef Shoot_H
#define Shoot_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

#include "Commands/ShooterPIDSet.h"
#include "Commands/WaitForShooter.h"
#include "Commands/ShooterPunchSet.h"

class Shoot: public CommandGroup
{
private:
	std::unique_ptr<Command> shooterPIDSet;
	std::unique_ptr<Command> waitForShooter;
	std::unique_ptr<Command> shooterPunchSet;
public:
	Shoot();
};

#endif
