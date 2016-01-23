#include "WPILib.h"
#include "CommandBase.h"

//Import commands used in Robot.cpp
#include "Commands/DriveWithJoysticks.h"

class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	std::unique_ptr<Command> driveWithJoysticks;
	std::unique_ptr<SendableChooser> chooser;

	void RobotInit()
	{
		CommandBase::init();

		driveWithJoysticks.reset(new DriveWithJoysticks());

		chooser.reset(new SendableChooser());
		SmartDashboard::PutData("Auto Modes", chooser.get());
	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//Grabs auto command from dashboard and runs it
		autonomousCommand.reset((Command*) chooser->GetSelected());
		if (autonomousCommand != NULL)
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
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

		//Start command you want to run in teleop
		driveWithJoysticks->Start();
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

