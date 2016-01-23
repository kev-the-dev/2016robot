#include "StartTeleCommands.h"

StartTeleCommands::StartTeleCommands()
{
	//Create safe command pointers
	driveWithJoysticks.reset(new DriveWithJoysticks);

	//Start them all in parallel
	AddParallel(driveWithJoysticks.get());
}
