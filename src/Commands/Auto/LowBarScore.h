#ifndef LowBarScore_H
#define LowBarScore_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class LowBarScore: public CommandGroup
{
private:
	static double turnAngle;
	static double angle;
public:
	LowBarScore();
};

#endif
