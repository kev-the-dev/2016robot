#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> armMotor;
	std::shared_ptr<Potentiometer> armPot;
	std::unique_ptr<PIDController> armPID;

	static float P;
	static float I;
	static float D;

	static float percentageTolerance;
public:
	Arm();
	void Set(double x);
	void InitDefaultCommand();

	static double loweredPot;
	static double shootingPot;

	void EnablePID();
	void DisablePID();
	bool IsPIDEnabled();
	void SetSetpoint(double x);
	bool OnTarget();
	double GetPot();
};

#endif
