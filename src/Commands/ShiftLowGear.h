#ifndef ShiftLowGear_H
#define ShiftLowGear_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShiftLowGear: public CommandBase
{
public:
	ShiftLowGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
