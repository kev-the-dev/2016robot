#include "WPILib.h"
#include "CommandBase.h"

//Import commands used in Robot.cpp
#include "Commands/StartTeleCommands.h"

#include <string>
#include "OI.h"

#include "RiptideRecorder/RiptideRecorder.h"

//This is the robot class
class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	std::unique_ptr<Command> teleCommands;
	std::shared_ptr<USBCamera> cam;
	void RobotInit()
	{

		//cam.reset(new USBCamera("cam0",true));
		//cam->OpenCamera();
		//CameraServer::GetInstance()->StartAutomaticCapture(cam);
		CommandBase::init();

		teleCommands.reset(new StartTeleCommands());

		SmartDashboard::PutBoolean("Pressure Switch", RobotMap::pressureSwitch->Get());

		SmartDashboard::PutData("Running Commands",Scheduler::GetInstance());

		#ifdef DEBUG
		std::cout << "RobotInit" << std::endl;
		#endif
	}

	void DisabledInit()
	{
		#ifdef DEBUG
		std::cout << "DisabledInit" << std::endl;
		#endif
		Scheduler::GetInstance()->RemoveAll();
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
//		#ifdef REAL
//		RobotMap::compressor->Start();
//		#endif

		#ifdef DEBUG
		std::cout << "AutoInit" << std::endl;
		#endif

		CommandBase::driveSystem->ResetGyro();

		//Grabs auto command from dashboard and runs it
		autonomousCommand.release();
		autonomousCommand.reset((Command*) CommandBase::oi->chooser->GetSelected());
		if (autonomousCommand != nullptr)
			#ifdef DEBUG
			std::cout << "Auto Command: " << autonomousCommand->GetName() << std::endl;
			#endif
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		if (RobotMap::pressureSwitch->Get()) {
			RobotMap::compressor->Stop();
		} else RobotMap::compressor->Start();

		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
//		#ifdef REAL
//		RobotMap::compressor->Start();
//		#endif
//		RobotMap::compressor->Stop();

		#ifdef DEBUG
		std::cout << "TeleInit" << std::endl;
		#endif
		CommandBase::shooterPunch->Set(DoubleSolenoid::kReverse);
		//Starts compressing air at start of teleop

		// Makes sure Auto command is stopped
		if (autonomousCommand != nullptr)
			autonomousCommand->Cancel();

		//Start command you want to run in teleop
		teleCommands->Start();
	}

	void TeleopPeriodic()
	{
		//Runs all current commands
		SmartDashboard::PutBoolean("Pressure Switch", RobotMap::pressureSwitch->Get());
		Scheduler::GetInstance()->Run();

		if (RobotMap::pressureSwitch->Get()) {
			RobotMap::compressor->Stop();
		} else RobotMap::compressor->Start();
	}
	void TestInit()
	{
		#ifdef DEBUG
		std::cout << "TestInit" << std::endl;
		#endif

		#ifdef REAL
		RobotMap::compressor->Start();
		#endif
	}
	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)
