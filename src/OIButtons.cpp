#include "OI.h"

//Commands
#include "Commands/LifterSet.h"
#include "Commands/LiftToSwitch.h"
#include "Commands/RotateX.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterSet.h"

void OI::SetButtons()
{
	shootCommand.reset(new Shoot());
	badShootCommand.reset(new ShooterSet(1));
	badIntakeCommand.reset(new ShooterSet(-1));
	liftToSwitchCommand.reset( new LiftToSwitch());
	stopShooterCommand.reset(new ShooterSet(0));

	badIntakeButton->WhileHeld(badIntakeCommand.get());
	badIntakeButton->WhenReleased(stopShooterCommand.get());
	badShootButton->WhileHeld(badShootCommand.get());
	badShootButton->WhenReleased(stopShooterCommand.get());
	shootButton->WhenPressed(shootCommand.get());

	SmartDashboard::PutData("Lift to Switch",liftToSwitchCommand.get());

	SmartDashboard::PutData("Extend",new LifterSet(Lifter::kForward));
	SmartDashboard::PutData("Retract",new LifterSet(Lifter::kReverse));
	SmartDashboard::PutData("On",new LifterSet(Lifter::kOn));
	SmartDashboard::PutData("Off", new LifterSet(Lifter::kOff));
	SmartDashboard::PutData("RotateX", new RotateX(30));
}
