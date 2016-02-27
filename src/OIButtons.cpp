#include "OI.h"

//Commands
#include "Commands/LifterSet.h"
#include "Commands/LiftToSwitch.h"
#include "Commands/RotateX.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterSet.h"
#include "Commands/ShooterWithJoystick.h"
#include "Commands/Auto/DriveAuto.h"
#include "Commands/ShooterPunchSet.h"
#include "Commands/ArmWithJoystick.h"
#include "Commands/AutoAimShoot.h"
#include "Commands/Auto/LowBarForward.h"
#include "Commands/Auto/DoNothing.h"
#include "Commands/Auto/LowBarScore.h"
#include "Commands/Auto/SpyBoxAuto.h"

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

	mac1Button->ToggleWhenPressed(mac1->NewRecordFileCommand("/home/lvuser/mac1.csv"));
	mac2Button->ToggleWhenPressed(mac2->NewRecordFileCommand("/home/lvuser/mac2.csv"));


	chooser->AddDefault("Do Nothing", (Command*) new DoNothing() );
	chooser->AddObject("Low Bar Forward",new LowBarForward());
	chooser->AddObject("Low Bar Score",new LowBarScore());
	chooser->AddObject("Spy Box Score",new SpyBoxAuto());
	chooser->AddObject("mac1", mac1->NewPlayFileCommand("/home/lvuser/mac1.csv"));
	chooser->AddObject("mac2", mac2->NewPlayFileCommand("/home/lvuser/mac2.csv"));

	SmartDashboard::PutData("Record",mac1->NewRecordFileCommand("test.csv"));
	SmartDashboard::PutData("Auto Modes", chooser);
}
