#include "WPILib.h"
#include "CommandBase.h"

//Commands used
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
	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
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

