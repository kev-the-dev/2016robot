#ifndef ShiftHighGear_H
#define ShiftHighGear_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShiftHighGear: public CommandBase
{
public:
	ShiftHighGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
