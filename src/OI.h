#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	//Joysticks

	std::unique_ptr<Joystick> stickMiddle;
	std::unique_ptr<Joystick> stickRight;

	//Joystick Buttons
	std::unique_ptr<JoystickButton> shiftLowButton;
	std::unique_ptr<JoystickButton> shiftHighButton;

	//Commands used by buttons
	std::unique_ptr<Command> liftToSwitchCommand;

	void SetButtons();
public:
	OI();
	std::unique_ptr<Joystick> stickLeft;
	float GetDriveY();
	float GetDriveRotation();
	bool GetPIDButton();
};

#endif
