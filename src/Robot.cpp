#include "WPILib.h"
#include "CommandBase.h"

//Import commands used in Robot.cpp
#include "Commands/StartTeleCommands.h"
#include "Commands/Auto/LowBarForward.h"
#include "Commands/Auto/DoNothing.h"
#include "Commands/Auto/LowBarScore.h"
#include "Commands/Auto/SpyBoxAuto.h"

#include "RiptideRecorder/RiptideRecorder.h"

//This is the robot class
class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	std::unique_ptr<Command> teleCommands;
	std::unique_ptr<SendableChooser> chooser;
	void RobotInit()
	{
		//CameraServer::GetInstance()->StartAutomaticCapture(0);
		CommandBase::init();

		teleCommands.reset(new StartTeleCommands());
		chooser.reset(new SendableChooser());

		//Autonomous choices
		chooser->AddDefault("Do Nothing", (Command*) new DoNothing() );
		chooser->AddObject("Low Bar Forward",new LowBarForward());
		chooser->AddObject("Low Bar Score",new LowBarScore());
		chooser->AddObject("Spy Box Score",new SpyBoxAuto());

		SmartDashboard::PutData("Auto Modes", chooser.get());
		SmartDashboard::PutData("Running Commands",Scheduler::GetInstance());
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
		CommandBase::shooterPunch->Set(DoubleSolenoid::kReverse);
		//Starts compressing air at start of teleop

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
	void TestInit()
	{
		RobotMap::compressor->Start();
	}
	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)
