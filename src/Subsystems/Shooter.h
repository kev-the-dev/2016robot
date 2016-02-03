#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static float defP;
	static float defI;
	static float defD;


	//PID values
	float P;
	float I;
	float D;

	std::shared_ptr<SpeedController> shooterLeft;
	std::shared_ptr<SpeedController> shooterRight;
	std::shared_ptr<Encoder> shooterLeftEncoder;
	std::shared_ptr<Encoder> shooterRightEncoder;
	std::unique_ptr<PIDController> leftPID;
	std::unique_ptr<PIDController> rightPID;

	bool PIDenabled;
public:
	Shooter();
	void Set(float x);
	void InitDefaultCommand();
	void EnablePID();
	void DisablePID();
	bool IsPIDEnabled();
};

#endif
