#include "OI.h"

//Commands
#include "Commands/LifterSet.h"
#include "Commands/LiftToSwitch.h"
#include "Commands/Drive/RotateX.h"
#include "Commands/Shooter/ShooterSet.h"
#include "Commands/Auto/DriveAuto.h"
#include "Commands/Punch/ShooterPunchSet.h"
#include "Commands/Arm/ArmWithJoystick.h"
#include "Commands/AutoAimShoot.h"
#include "Commands/Auto/LowBarForward.h"
#include "Commands/Auto/DoNothing.h"
#include "Commands/Auto/LowBarScore.h"
#include "Commands/Auto/SpyBoxAuto.h"
#include "Commands/Auto/AutoDriveTest.h"
#include "Commands/Auto/AutoArmTest.h"
#include "Commands/Auto/LowArmAuto.h"


void OI::SetButtons()
{
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

	//mac1Button->ToggleWhenPressed(mac1->NewRecordFileCommand("/home/lvuser/mac1.csv"));
	//mac2Button->ToggleWhenPressed(mac2->NewRecordFileCommand("/home/lvuser/mac2.csv"));


	chooser->AddDefault("Do Nothing", (Command*) new DoNothing() );
	chooser->AddObject("Low Bar",new LowBarForward());
	//chooser->AddObject("mac1", mac1->NewPlayFileCommand("/home/lvuser/mac1.csv"));
	//chooser->AddObject("mac2", mac2->NewPlayFileCommand("/home/lvuser/mac2.csv"));

	//SmartDashboard::PutData("Record",mac1->NewRecordFileCommand("test.csv"));
	SmartDashboard::PutData("Auto Modes", chooser);

	SmartDashboard::PutData("Auto Drive",new AutoDriveTest());
	SmartDashboard::PutData("Auto Arm",new AutoArmTest());
	SmartDashboard::PutData("Arm Lower Auto", new LowArmAuto());
}
