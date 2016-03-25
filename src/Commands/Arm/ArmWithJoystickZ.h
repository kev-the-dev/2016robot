#ifndef ArmWithJoystickZ_H
#define ArmWithJoystickZ_H

#include "CommandBase.h"
#include "WPILib.h"

class ArmWithJoystickZ: public CommandBase
{
public:
	ArmWithJoystickZ();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
