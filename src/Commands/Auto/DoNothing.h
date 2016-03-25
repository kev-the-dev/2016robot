#ifndef DoNothing_H
#define DoNothing_H

#include "CommandBase.h"
#include "WPILib.h"

class DoNothing: public CommandBase
{
public:
	DoNothing();
	bool IsFinished();
	virtual void End();
	virtual void Execute();
	virtual void Initialize();
	virtual void Interrupted();
};

#endif
