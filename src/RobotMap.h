#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <string>

#include "RiptideRecorder/RiptideRecorder.h"

class RobotMap
{
public:
	static void init();

	static std::shared_ptr<Recorder> rec;
	//Static pointers to all sensors and actuators

	//Driving
	static std::shared_ptr<SpeedController> leftOne;
	static std::shared_ptr<SpeedController> leftTwo;
	static std::shared_ptr<SpeedController> rightOne;
	static std::shared_ptr<SpeedController> rightTwo;
	static std::shared_ptr<RobotDrive> drive;
	static std::shared_ptr<Gyro> gyro;

	//Pnuematics
	#ifdef REAL
	static std::shared_ptr<Compressor> compressor;
	#endif

	//Arm
	static std::shared_ptr<SpeedController> armMotor;
	static std::shared_ptr<Potentiometer> armPot;

	//Shooter
	static std::shared_ptr<SpeedController> shooterLeft;
	static std::shared_ptr<SpeedController> shooterRight;
	static std::shared_ptr<Encoder> shooterLeftEncoder;
	static std::shared_ptr<Encoder> shooterRightEncoder;

	//Lifter
	static std::shared_ptr<Solenoid> lifterPistonForward;
	static std::shared_ptr<Solenoid> lifterPistonReverse;
	static std::shared_ptr<DigitalInput> lifterSwitch;

	//Shooter punch
	static std::shared_ptr<DoubleSolenoid> shooterPunch;
};

#endif
