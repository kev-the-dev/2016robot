#include "StartTeleCommands.h"

StartTeleCommands::StartTeleCommands()
{
	//Create safe command pointers
	driveWithJoysticks.reset(new DriveWithJoysticks);
	smartDashboardInfo.reset(new SmartDashboardInfo());
	armWithJoystick.reset(new ArmWithJoystick());

	//Start them all in parallel
	AddParallel(driveWithJoysticks.get());
	AddParallel(smartDashboardInfo.get());
	AddParallel(armWithJoystick.get());
}
