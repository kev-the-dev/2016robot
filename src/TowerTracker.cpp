#include <TrackTower.h>

TrackTower::TrackTower() {
	cap.reset(new cv::VideoCapture(0));
	isRunning = false;
}

TrackTower::~TrackTower()
{

}
bool TrackTower::IsRunning()
{
	return isRunning;
}
void TrackTower::run(TrackTower* t)
{
	cv::Mat frame;
	t->Lock();
	if (!t->cap->isOpened())
	{
		t->cap->open(0);
	}
	do {
		//Process a frame or a few
		*t->cap >> frame;


		//Set data to be grabbed

		//Ensure thread safety and a wait so not maxing cpu
		t->Unlock();
		Wait(waitTime);
		t->Lock();
	} while (t->IsRunning());
}
void TrackTower::Stop()
{
	isRunning = false;
}
void TrackTower::Start()
{
	if (!isRunning) {
		isRunning = true;
		task.reset(new Task("RunVision",run,this));
	}
}
void TrackTower::Lock()
{
	mut.lock();
}
void TrackTower::Unlock()
{
	mut.unlock();
}
