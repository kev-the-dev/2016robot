#ifndef ROTATEX_H
#define ROTATEX_H

#include "../CommandBase.h"
#include "WPILib.h"

class RotateX: public PIDCommand
{
private:
	float driveY,angle;
public:
	void UsePIDOutput(double x);
	double ReturnPIDInput();

	RotateX(float a);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
