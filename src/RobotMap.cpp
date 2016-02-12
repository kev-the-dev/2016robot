#include "RobotMap.h"

//Set all sensors/actuator to NULL
std::shared_ptr<SpeedController> RobotMap::leftOne;
std::shared_ptr<SpeedController> RobotMap::leftTwo;
std::shared_ptr<SpeedController> RobotMap::rightOne;
std::shared_ptr<SpeedController> RobotMap::rightTwo;
std::shared_ptr<RobotDrive> RobotMap::drive;
std::shared_ptr<Gyro> RobotMap::gyro;
std::shared_ptr<Compressor> RobotMap::compressor;
std::shared_ptr<SpeedController> RobotMap::armMotor;
std::shared_ptr<Potentiometer> RobotMap::armPot;
std::shared_ptr<SpeedController> RobotMap::shooterLeft;
std::shared_ptr<SpeedController> RobotMap::shooterRight;
std::shared_ptr<Encoder> RobotMap::shooterLeftEncoder;
std::shared_ptr<Encoder> RobotMap::shooterRightEncoder;
std::shared_ptr<Solenoid> RobotMap::lifterPistonForward;
std::shared_ptr<Solenoid> RobotMap::lifterPistonReverse;
std::shared_ptr<DigitalInput> RobotMap::lifterSwitch;
void RobotMap::init()
{
	//Init all sensors/actuators with proper port #, add to LiveWindow
	leftOne.reset(new Talon(0));
	leftTwo.reset(new Talon(1));
	rightOne.reset(new Talon(2));
	rightTwo.reset(new Talon(3));
	drive.reset(new RobotDrive(leftOne,leftTwo,rightOne,rightTwo));
	gyro.reset(new AnalogGyro(0));

	compressor.reset(new Compressor(0));

	armMotor.reset(new Talon(4));
	//AnalogPotentiometer (int channel, double fullRange=1.0, double offset=0.0)
	armPot.reset(new AnalogPotentiometer(0,1,0));

	shooterLeft.reset(new Talon(5));
	shooterRight.reset(new Talon(6));
	shooterLeftEncoder.reset(new Encoder(0,1));
	shooterRightEncoder.reset(new Encoder(2,3));

	lifterPistonForward.reset(new Solenoid(1,2));
	lifterPistonReverse.reset(new Solenoid(1,3));
	lifterSwitch.reset(new DigitalInput(4));
}
