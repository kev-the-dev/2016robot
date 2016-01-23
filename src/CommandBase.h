#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"

//Include all subsystems
#include "Subsystems/DriveSystem.h"
#include "Subsystems/Arm.h"
#include "Subsystems/Shooter.h"

#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
private:
	static void SetButtons();
protected:
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveSystem> driveSystem;
	static std::unique_ptr<Arm> arm;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<Shooter> shooter;
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
};

#endif
