#ifndef WaitForArmSimple_H
#define WaitForArmSimple_H

#include "../CommandBase.h"
#include "WPILib.h"

class WaitForArmSimple: public CommandBase
{
public:
	WaitForArmSimple(float x);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float val;
};

#endif
