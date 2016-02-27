#include "OI.h"

OI::OI()
{
	mac1 = RobotMap::rec->macro();
	mac2 = RobotMap::rec->macro();

	// Process operator interface input here.
	stickLeft.reset(new Joystick(0));
	stickMiddle.reset(new Joystick(1));
	stickRight.reset(new Joystick(2));

	//shootButton.reset(new JoystickButton(stickRight.get(),1));
	badShootButton.reset(new JoystickButton(stickRight.get(),3));
	badIntakeButton.reset(new JoystickButton(stickRight.get(),2));
	shootButton.reset(new JoystickButton(stickRight.get(),1));

	//armWithZButton.reset(new JoystickButton(stickRight.get()),11);
	mac1Button.reset(new JoystickButton(stickLeft.get(),6));
	mac2Button.reset(new JoystickButton(stickLeft.get(),7));

	chooser = new SendableChooser();

	SetButtons();
}
float OI::GetDriveY()
{
	return -stickLeft->GetY();
}
float OI::GetDriveRotation()
{
	return -stickMiddle->GetX();
}
bool OI::GetReverseDriveButton()
{
	return stickLeft->GetRawButton(1);
}
float OI::GetOpY()
{
	return stickRight->GetY();
}
bool OI::GetManShoot()
{
	return stickRight->GetRawButton(1);
}
float OI::GetOpZ()
{
	return stickRight->GetZ();
}
