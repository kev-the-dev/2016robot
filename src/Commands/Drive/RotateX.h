#ifndef ROTATEX_H
#define ROTATEX_H

#include "CommandBase.h"
#include "WPILib.h"

class RotateX: public PIDCommand
{
private:
	float driveY,angle;
	static float p,i,d;
public:
	void UsePIDOutput(double x);
	double ReturnPIDInput();

	RotateX(float a);
	RotateX(float a, float y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
