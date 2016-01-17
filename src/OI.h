#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"

class OI
{
private:
	Joystick* stickLeft;
	Joystick* stickMiddle;
	Joystick* stickRight;
public:
	OI();
	float GetDriveY();
	float GetDriveRotation();
};

#endif
