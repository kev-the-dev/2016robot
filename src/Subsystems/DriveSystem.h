#ifndef DriveSystem_H
#define DriveSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<RobotDrive> drive;
public:
	DriveSystem();
	void InitDefaultCommand();
	void Drive(float y, float rotation);
};

#endif
