#ifndef ShooterPIDSet_H
#define ShooterPIDSet_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShooterPIDSet: public CommandBase
{
private:
	double rate;
public:
	ShooterPIDSet(double r);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
