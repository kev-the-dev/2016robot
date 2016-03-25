#include "DoNothing.h"

DoNothing::DoNothing() : CommandBase("DoNothing")
{
}
void DoNothing::Initialize()
{

}
bool DoNothing::IsFinished()
{
	return true;
}
void DoNothing::End()
{

}
void DoNothing::Execute()
{

}

void DoNothing::Interrupted()
{

}
