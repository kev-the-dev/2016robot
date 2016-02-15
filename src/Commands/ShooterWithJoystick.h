#ifndef ShooterWithJoystick_H
#define ShooterWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShooterWithJoystick: public CommandBase
{
public:
	ShooterWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
