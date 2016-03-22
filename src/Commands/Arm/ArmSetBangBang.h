#ifndef ArmSetBangBang_H
#define ArmSetBangBang_H

#include "CommandBase.h"
#include "WPILib.h"

class ArmSetBangBang: public CommandBase
{
public:
	ArmSetBangBang(float a);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float Error();
	float angle;
};

#endif
