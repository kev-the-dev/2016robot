#ifndef SmartDashboardInfo_H
#define SmartDashboardInfo_H

#include "../CommandBase.h"
#include "WPILib.h"

class SmartDashboardInfo: public CommandBase
{
public:
	SmartDashboardInfo();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
