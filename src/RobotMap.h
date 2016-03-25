#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <string>

#include "RiptideRecorder/RiptideRecorder.h"

/*
 * The RobotMap classs is used to construct and configure all the sensors and actuators on the robot
 * Various subsstems copy the static memebers of RobotMap
 */
class RobotMap
{
public:
	static void init();

	//static std::shared_ptr<Recorder> rec;

	//Driving
	static std::shared_ptr<SpeedController> leftOne;
	static std::shared_ptr<SpeedController> leftTwo;
	static std::shared_ptr<SpeedController> rightOne;
	static std::shared_ptr<SpeedController> rightTwo;
	static std::shared_ptr<RobotDrive> drive;
	static std::shared_ptr<Gyro> gyro;

	//Pnuematics
	#ifndef SIMULATION
	static std::shared_ptr<Compressor> compressor;
	#endif

	//Arm
	static std::shared_ptr<SpeedController> armMotor;
	static std::shared_ptr<Potentiometer> armPot;

	//Shooter
	static std::shared_ptr<SpeedController> shooterLeft;
	static std::shared_ptr<SpeedController> shooterRight;

	//Lifter
	static std::shared_ptr<Solenoid> lifterPistonForward;
	static std::shared_ptr<Solenoid> lifterPistonReverse;
	static std::shared_ptr<DigitalInput> lifterSwitch;

	static std::shared_ptr<DigitalInput> armBottomSwitch;

	//Shooter punch
	static std::shared_ptr<DoubleSolenoid> shooterPunch;

	static std::shared_ptr<DigitalInput> pressureSwitch;
};

#endif
