#include "WPILib.h"
#include "CommandBase.h"

//Import commands used in Robot.cpp
#include "Commands/DriveWithJoysticks.h"

class Robot: public IterativeRobot
{
private:
	Command* autonomousCommand;
	Command* driveWithJoysticks;
	SendableChooser *chooser;

	void RobotInit()
	{
		CommandBase::init();

		driveWithJoysticks = new DriveWithJoysticks();

		chooser = new SendableChooser();
		SmartDashboard::PutData("Auto Modes", chooser);
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
		autonomousCommand = (Command*) chooser->GetSelected();
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
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

