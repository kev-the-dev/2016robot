#ifndef SRC_TOWERTRACKER_H_
#define SRC_TOWERTRACKER_H_

#include "WPILib.h"

//OpenCV test
#include "opencv2/opencv.hpp"

const double waitTime = 0.05;

class TowerTracker {
private:
	priority_mutex mut;
	bool isRunning;
	void run();
	Task task;
	cv::VideoCapture cap;
public:
	TowerTracker();
	void Lock();
	void Unlock();
	void Stop();
	void Start();
	bool IsRunning();
	virtual ~TowerTracker();
};

#endif /* SRC_TRACKTOWER_H_ */
