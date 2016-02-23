#include "OI.h"

//Commands
#include "Commands/LifterSet.h"
#include "Commands/LiftToSwitch.h"
#include "Commands/RotateX.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterSet.h"
#include "Commands/ShooterWithJoystick.h"
#include "Commands/Auto/DoForTime.h"
#include "Commands/Auto/DriveAuto.h"
#include "Commands/ShooterPunchSet.h"
#include "Commands/ArmWithJoystick.h"

void OI::SetButtons()
{
	shootCommand.reset(new Shoot());
	punchInCommand.reset(new ShooterPunchSet(DoubleSolenoid::kReverse));
	punchOutCommand.reset(new ShooterPunchSet(DoubleSolenoid::kForward));
	badShootCommand.reset(new ShooterSet(1));
	badIntakeCommand.reset(new ShooterSet(-1));
	liftToSwitchCommand.reset( new LiftToSwitch());
	stopShooterCommand.reset(new ShooterSet(0));

	badIntakeButton->WhileHeld(badIntakeCommand.get());
	badIntakeButton->WhenReleased(stopShooterCommand.get());
	badShootButton->WhileHeld(badShootCommand.get());
	badShootButton->WhenReleased(stopShooterCommand.get());
	shootButton->WhenPressed(punchOutCommand.get());
	shootButton->WhenReleased(punchInCommand.get());

	//SmartDashboard::PutData("RotateX", new RotateX(30));
	SmartDashboard::PutData("Rotate to Zero", (PIDCommand*) new RotateX(0));
	SmartDashboard::PutData("Forward Safe", new DoForTime(std::unique_ptr<Command>(new RotateX(0,0.5)),5));
	SmartDashboard::PutData("Move Forward", (Command*) new DoForTime(std::unique_ptr<Command>(new DriveAuto(0.5,0)),5));
}
