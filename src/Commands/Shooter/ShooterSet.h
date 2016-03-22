#ifndef ShooterSet_H
#define ShooterSet_H

#include "CommandBase.h"
#include "WPILib.h"

class ShooterSet: public CommandBase
{
private:
	double speed;
public:
	ShooterSet(double s);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
