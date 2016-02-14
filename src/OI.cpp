#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	stickLeft.reset(new Joystick(0));
	stickMiddle.reset(new Joystick(1));
	stickRight.reset(new Joystick(2));

	shootButton.reset(new JoystickButton(stickRight.get(),1));
	badShootButton.reset(new JoystickButton(stickMiddle.get(),2));
	badIntakeButton.reset(new JoystickButton(stickMiddle.get(),3));

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
bool OI::GetReverseDriveButton()
{
	return stickLeft->GetRawButton(1);
}
