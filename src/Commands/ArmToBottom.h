#ifndef ArmToBottom_H
#define ArmToBottom_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmToBottom: public CommandBase
{
public:
	ArmToBottom();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
