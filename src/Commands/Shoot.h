#ifndef Shoot_H
#define Shoot_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

#include "Commands/Auto/DoForTime.h"
#include "Commands/ShooterPunchSet.h"

class Shoot: public CommandGroup
{
private:
	std::unique_ptr<Command> punchForward;
	std::unique_ptr<Command> punchReverse;
	std::unique_ptr<Command> doForTime;
public:
	Shoot();
};

#endif
