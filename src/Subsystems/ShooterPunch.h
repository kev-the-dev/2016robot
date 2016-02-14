#ifndef ShooterPunch_H
#define ShooterPunch_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterPunch: public Subsystem
{
private:
	std::shared_ptr<DoubleSolenoid> punch;
	DoubleSolenoid::Value state;
public:
	ShooterPunch();
	void Set(DoubleSolenoid::Value v);
	DoubleSolenoid::Value GetState();
	void InitDefaultCommand();
};

#endif
