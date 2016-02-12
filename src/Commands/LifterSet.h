#ifndef LifterSet_H
#define LifterSet_H

#include "../CommandBase.h"
#include "WPILib.h"

class LifterSet: public CommandBase
{
private:
	Lifter::State state;
public:
	LifterSet(Lifter::State s);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
