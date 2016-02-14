#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	stickLeft.reset(new Joystick(0));
	stickMiddle.reset(new Joystick(1));
	stickRight.reset(new Joystick(2));

	shiftLowButton.reset(new JoystickButton(stickRight.get(),3));

	shiftHighButton.reset(new JoystickButton(stickRight.get(),4));

	SetButtons();
}
float OI::GetDriveY()
{
	return -stickLeft->GetY();
}
float OI::GetDriveRotation()
{
	return -stickMiddle->GetX();
}
bool OI::GetPIDButton()
{
	return stickLeft->GetRawButton(1);
}
