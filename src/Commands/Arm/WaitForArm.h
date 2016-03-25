#ifndef WaitForArm_H
#define WaitForArm_H

#include "CommandBase.h"
#include "WPILib.h"

class WaitForArm: public CommandBase
{
private:
	static float maxError;
public:
	WaitForArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
