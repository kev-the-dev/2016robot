#include <TowerTracker.h>

TowerTracker::TowerTracker() {
	cap = cv::VideoCapture(0);
	isRunning = false;
}

TowerTracker::~TowerTracker()
{

}
bool TowerTracker::IsRunning()
{
	return isRunning;
}
void TowerTracker::run()
{
	cv::Mat frame;
	Lock();
	if (!cap.isOpened())
	{
		cap.open(0);
	}
	do {
		//Process a frame or a few
		cap.read(frame);


		//Set data to be grabbed

		//Ensure thread safety and a wait so not maxing cpu
		Unlock();
		Wait(waitTime);
		Lock();
	} while (IsRunning());
}
void TowerTracker::Stop()
{
	isRunning = false;
}
void TowerTracker::Start()
{
	if (!isRunning) {
		isRunning = true;
		task = Task("RunVision",&TowerTracker::run,this);
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
