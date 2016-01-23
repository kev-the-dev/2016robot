#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	std::unique_ptr<Joystick> stickLeft;
	std::unique_ptr<Joystick> stickMiddle;
	std::unique_ptr<Joystick> stickRight;
	std::unique_ptr<JoystickButton> shiftLowButton;
	std::unique_ptr<JoystickButton> shiftHighButton;
public:
	OI();
	float GetDriveY();
	float GetDriveRotation();
};

#endif
