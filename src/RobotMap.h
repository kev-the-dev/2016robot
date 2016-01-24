#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {
public:
	static void init();

	//Static pointers to all sensors and actuators

	//Driving
	static std::shared_ptr<SpeedController> leftOne;
	static std::shared_ptr<SpeedController> leftTwo;
	static std::shared_ptr<SpeedController> rightOne;
	static std::shared_ptr<SpeedController> rightTwo;
	static std::shared_ptr<RobotDrive> drive;

	//Shifting
	static std::shared_ptr<Compressor> compressor;
	static std::shared_ptr<DoubleSolenoid> leftTransmission;
	static std::shared_ptr<DoubleSolenoid> rightTransmission;

	//Arm
	static std::shared_ptr<SpeedController> armMotor;

	//Shooter
	static std::shared_ptr<SpeedController> shooterLeft;
	static std::shared_ptr<SpeedController> shooterRight;
};

#endif
