#ifndef ArmSetSimple_H
#define ArmSetSimple_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class ArmSetSimple: public CommandGroup
{
public:
	ArmSetSimple(float speed, float val);
};

#endif
