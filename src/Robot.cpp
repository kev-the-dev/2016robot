#include "WPILib.h"
#include "CommandBase.h"

//Import commands used in Robot.cpp
#include "Commands/StartTeleCommands.h"
#include "Commands/Auto/DoNothing.h"
#include "Commands/Auto/DoForTime.h"
#include "Commands/Auto/DriveAuto.h"

//This is the robot class
class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	std::unique_ptr<Command> teleCommands;
	std::unique_ptr<SendableChooser> chooser;

	void RobotInit()
	{
		CommandBase::init();

		teleCommands.reset(new StartTeleCommands());
		chooser.reset(new SendableChooser());

		//Autonomous choices
		chooser->AddDefault("Do Nothing", (Command*) new DoNothing() );
		chooser->AddObject("Drive Forward",new DoForTime(std::unique_ptr<Command>(new DriveAuto(1,0)),1));

		SmartDashboard::PutData("Auto Modes", chooser.get());
	}

	void DisabledInit()
	{
		Scheduler::GetInstance()->RemoveAll();
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//Grabs auto command from dashboard and runs it
		autonomousCommand.reset((Command*) chooser->GetSelected());
		if (autonomousCommand.get() != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		//Starts compressing air at start of teleop
		RobotMap::compressor->Start();

		// Makes sure Auto command is stopped
		if (autonomousCommand.get() != NULL)
			autonomousCommand->Cancel();

		//Start command you want to run in teleop
		teleCommands->Start();
	}

	void TeleopPeriodic()
	{
		//Runs all current commands
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)
