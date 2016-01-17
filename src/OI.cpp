#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	stickLeft = new Joystick(1);
	stickMiddle = new Joystick(2);
	stickRight = new Joystick(3);
}
float OI::GetDriveY()
{
	return stickLeft->GetY();
}
float OI::GetDriveRotation()
{
	return stickMiddle->GetX();
}
