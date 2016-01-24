#include "OI.h"

//Commands
#include "Commands/ShiftLowGear.h"

void OI::SetButtons()
{
	shiftLowGearCommand.reset(new ShiftLowGear());
	shiftLowButton->WhenPressed(shiftLowGearCommand.get());
}
