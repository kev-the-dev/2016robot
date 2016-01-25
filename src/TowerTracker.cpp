#include <TowerTracker.h>

TowerTracker::TowerTracker() {
	cap.reset(new cv::VideoCapture(0));
	isRunning = false;
}

TowerTracker::~TowerTracker()
{

}
bool TowerTracker::IsRunning()
{
	return isRunning;
}
void TowerTracker::run(TowerTracker* t)
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
void TowerTracker::Stop()
{
	isRunning = false;
}
void TowerTracker::Start()
{
	if (!isRunning) {
		isRunning = true;
		task.reset(new Task("RunVision",run,this));
	}
}
void TowerTracker::Lock()
{
	mut.lock();
}
void TowerTracker::Unlock()
{
	mut.unlock();
}
