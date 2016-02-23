#ifndef DriveSystem_H
#define DriveSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<RobotDrive> drive;

	std::shared_ptr<Encoder> encoderLeft;
	std::shared_ptr<Encoder> encoderRight;
public:
	std::shared_ptr<Gyro> gyro;
	DriveSystem();
	void InitDefaultCommand();
	void Drive(float y, float rotation);
	double Distance();
	double Rate();
	float GyroAngle();
	void ResetGyro();
};

#endif
