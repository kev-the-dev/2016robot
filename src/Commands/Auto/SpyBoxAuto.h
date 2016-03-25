#ifndef SpyBoxAuto_H
#define SpyBoxAuto_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class SpyBoxAuto: public CommandGroup
{
private:
	static double angle;
public:
	SpyBoxAuto();
};

#endif
