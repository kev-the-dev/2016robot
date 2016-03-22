#ifndef ArmGoToNoPID_H
#define ArmGoToNoPID_H

#include "CommandBase.h"
#include "WPILib.h"

class ArmGoToNoPID: public CommandBase
{
private:
	double angle;
	double speed;
	static double defSpeed;
	void Init();
public:
	ArmGoToNoPID(double a);
	ArmGoToNoPID(double a, double s);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
