#ifndef StartTeleCommands_H
#define StartTeleCommands_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"


//Commands for tele
#include "DriveWithJoysticks.h"

class StartTeleCommands: public CommandGroup
{
private:
	std::unique_ptr<Command> driveWithJoysticks;
public:
	StartTeleCommands();
};

#endif
