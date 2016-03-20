#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem //,PIDOutput
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
//	static float P;
//	static float I;
//	static float D;
//
//	static float percentageTolerance;

	std::shared_ptr<SpeedController> shooterLeft;
	std::shared_ptr<SpeedController> shooterRight;
////	std::shared_ptr<Encoder> shooterLeftEncoder;
////	std::shared_ptr<Encoder> shooterRightEncoder;
////	std::unique_ptr<PIDController> leftPID;
////	std::unique_ptr<PIDController> rightPID;
////	std::unique_ptr<PIDController> onePID;
//
//	bool PIDenabled;
public:
	Shooter();
	void Set(float x);
	void InitDefaultCommand();
//	void PIDSet(float rate);
//	void EnablePID();
//	void DisablePID();
//	double LeftRate();
//	double RightRate();
//	bool LeftOnTarget();
//	bool RightOnTarget();
//	bool IsPIDEnabled();
//	void PIDWrite (float output);
//	const double SHOOTING_RATE = 500;
//	const double INTAKE_RATE = -200;
};

#endif
