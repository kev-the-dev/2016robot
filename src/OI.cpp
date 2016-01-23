#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	stickLeft.reset(new Joystick(1));
	stickMiddle.reset(new Joystick(2));
	stickRight.reset(new Joystick(3));

	shiftLowButton.reset(new JoystickButton(stickRight.get(),3));

	shiftHighButton.reset(new JoystickButton(stickRight.get(),4));

}
float OI::GetDriveY()
{
	return stickLeft->GetY();
}
float OI::GetDriveRotation()
{
	return stickMiddle->GetX();
}
