#ifndef AutoArmTest_H
#define AutoArmTest_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoArmTest: public CommandBase
{
public:
	AutoArmTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float x;
	float time;
	bool isGoing;
};

#endif
