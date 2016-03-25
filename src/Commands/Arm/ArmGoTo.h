#ifndef ArmGoTo_H
#define ArmGoTo_H

#include "CommandBase.h"
#include "WPILib.h"

class ArmGoTo: public CommandBase
{
private:
	double angle;
public:
	ArmGoTo(double a);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
