#ifndef DriveAtAngle_H
#define DriveAtAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveAtAngle: public PIDCommand
{
public:
	void PIDWrite (float output);
	double PIDGet();

	DriveAtAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
