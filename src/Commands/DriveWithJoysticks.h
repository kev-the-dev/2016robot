#ifndef DriveWithJoysticks_H
#define DriveWithJoysticks_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveWithJoysticks: public CommandBase
{
private:
	float kP,kI;
	float angle;
	int stackSize;
	std::deque<float > errors;
public:
	DriveWithJoysticks();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
