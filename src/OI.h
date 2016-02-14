#ifndef OI_H
#define OI_H

#include "WPILib.h"

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

	//Commands used by buttons
	std::unique_ptr<Command> liftToSwitchCommand;
	std::unique_ptr<Command> shootCommand;
	std::unique_ptr<Command> badShootCommand;
	std::unique_ptr<Command> badIntakeCommand;
	std::unique_ptr<Command> stopShooterCommand;
	void SetButtons();
public:
	OI();
	bool GetReverseDriveButton();
	float GetDriveY();
	float GetDriveRotation();
};

#endif
