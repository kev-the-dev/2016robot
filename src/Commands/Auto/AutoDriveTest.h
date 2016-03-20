#ifndef AutoDriveTest_H
#define AutoDriveTest_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoDriveTest: public CommandBase
{
public:
	AutoDriveTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float time;
	float speed;
};

#endif
