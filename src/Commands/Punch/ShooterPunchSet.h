#ifndef ShooterPunchSet_H
#define ShooterPunchSet_H

#include "CommandBase.h"
#include "WPILib.h"

class ShooterPunchSet: public CommandBase
{
private:
	DoubleSolenoid::Value state;
public:
	ShooterPunchSet(DoubleSolenoid::Value v);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
