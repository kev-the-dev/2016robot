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

	static float defP;
	static float defI;
	static float defD;

	float P;
	float I;
	float D;
public:
	Arm();
	void Set(double x);
	void InitDefaultCommand();

	void EnablePID();
	void DisablePID();
	bool IsPIDEnabled();
	void SetSetpoint(double x);
	float GetPIDError();
	double GetPot();
};

#endif
