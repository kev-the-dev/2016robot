#ifndef DoForTime_H
#define DoForTime_H

#include "CommandBase.h"
#include "WPILib.h"

class DoForTime: public WaitCommand
{
private:
	std::unique_ptr<Command> command;
public:
	DoForTime(std::unique_ptr<Command> c,double t);
	void Initialize();
	void End();
	void Interrupted();
};

#endif
