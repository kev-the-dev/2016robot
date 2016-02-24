#include "LowBarForward.h"

LowBarForward::LowBarForward()
{
	AddSequential(new DoForTime(std::unique_ptr<Command>(new RotateX(0,1)),5));
}
