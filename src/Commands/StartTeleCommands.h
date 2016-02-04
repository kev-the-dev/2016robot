#ifndef StartTeleCommands_H
#define StartTeleCommands_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"


//Commands for tele
#include "DriveWithJoysticks.h"
#include "SmartDashboardInfo.h"

class StartTeleCommands: public CommandGroup
{
private:
	std::unique_ptr<Command> driveWithJoysticks;
	std::unique_ptr<Command> smartDashboardInfo;
public:
	StartTeleCommands();
};

#endif
