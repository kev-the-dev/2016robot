#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDistance: public PIDCommand,CommandBase
{
private:
	double distance;
public:
	void PIDWrite (float output);
	double PIDGet();

	DriveDistance(double d);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
