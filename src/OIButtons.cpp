#include "OI.h"

//Commands
#include "Commands/LifterSet.h"
#include "Commands/LiftToSwitch.h"


void OI::SetButtons()
{
	liftToSwitchCommand.reset((Command*) new LiftToSwitch());
	SmartDashboard::PutData("Lift to Switch",liftToSwitchCommand.get());

	SmartDashboard::PutData("Extend",new LifterSet(Lifter::kForward));
	SmartDashboard::PutData("Retract",new LifterSet(Lifter::kReverse));
	SmartDashboard::PutData("On",new LifterSet(Lifter::kOn));
	SmartDashboard::PutData("Off", new LifterSet(Lifter::kOff));

}
