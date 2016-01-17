#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	stickLeft = new Joystick(JOYSTICK_LEFT_PORT);
	stickMiddle = new Joystick(JOYSTICK_MIDDLE_PORT);
	stickRight = new Joystick(JOYSTICK_RIGHT_PORT);
}
float OI::GetDriveY()
{
	return stickLeft->GetY();
}
float OI::GetDriveRotation()
{
	return stickMiddle->GetX();
}
