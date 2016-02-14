#ifndef ArmSet_H
#define ArmSet_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmSet: public CommandBase
{
private:
	double set_val;
public:
	ArmSet(double x);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
