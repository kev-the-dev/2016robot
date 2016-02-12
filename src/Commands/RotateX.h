#ifndef ROTATEX_H
#define ROTATEX_H

#include "../CommandBase.h"
#include "WPILib.h"

class RotateX: public PIDCommand,CommandBase
{
private:
	float driveY;
	float angle;
public:
	void PIDWrite (float output);
	double PIDGet();

	RotateX(float a);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
