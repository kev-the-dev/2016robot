#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "RiptideRecorder/RiptideRecorder.h"

class OI
{
private:
	//Joysticks

	std::unique_ptr<Joystick> stickMiddle;
	std::unique_ptr<Joystick> stickRight;
	std::unique_ptr<Joystick> stickLeft;

	//Joystick Buttons
	std::unique_ptr<JoystickButton> shootButton;
	std::unique_ptr<JoystickButton> badShootButton;
	std::unique_ptr<JoystickButton> badIntakeButton;
	std::unique_ptr<JoystickButton> mac1Button;
	std::unique_ptr<JoystickButton> mac2Button;

	//Commands used by buttons
	std::unique_ptr<Command> liftToSwitchCommand;
	std::unique_ptr<Command> shootCommand;
	std::unique_ptr<Command> punchOutCommand;
	std::unique_ptr<Command> punchInCommand;
	std::unique_ptr<Command> badShootCommand;
	std::unique_ptr<Command> badIntakeCommand;
	std::unique_ptr<Command> stopShooterCommand;
	std::unique_ptr<Command> armToIntake;
	std::unique_ptr<Command> armToShooting;

	Macro* mac1;
	Macro* mac2;
	void SetButtons();
public:
	OI();
	bool GetReverseDriveButton();
	bool GetManShoot();
	bool GetManArm();
	float GetDriveY();
	float GetDriveRotation();
	float GetOpY();
	float GetOpZ();
};

#endif
