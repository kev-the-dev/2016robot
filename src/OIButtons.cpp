#include "OI.h"

//Commands
#include "Commands/LiftToSwitch.h"

void OI::SetButtons()
{
	liftToSwitchCommand.reset(new LiftToSwitch());
	SmartDashboard::PutData("Lift to Switch",liftToSwitchCommand.get());
}
