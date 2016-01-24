#ifndef DoNothing_H
#define DoNothing_H

#include "../CommandBase.h"
#include "WPILib.h"

class DoNothing: public CommandBase
{
public:
	DoNothing();
	bool IsFinished();
};

#endif
