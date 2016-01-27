#ifndef DriveAuto_H
#define DriveAuto_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveAuto: public CommandBase
{
private:
	double y;
	double rotation;
public:
	DriveAuto(double y, double rotation);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
