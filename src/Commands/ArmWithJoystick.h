#ifndef ArmWithJoystick_H
#define ArmWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmWithJoystick: public CommandBase
{
public:
	ArmWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
