#ifndef WaitForShooter_H
#define WaitForShooter_H

#include "../CommandBase.h"
#include "WPILib.h"

class WaitForShooter: public CommandBase
{
private:
	static float maxError;
public:
	WaitForShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
