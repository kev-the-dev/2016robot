#ifndef SRC_TRACKTOWER_H_
#define SRC_TRACKTOWER_H_

#include "WPILib.h"

//OpenCV test
#include "opencv2/opencv.hpp"

const double waitTime = 0.2;

class TrackTower {
private:
	priority_mutex mut;
	bool isRunning;
	static void run(TrackTower* t);
	std::unique_ptr<Task> task;
public:
	std::unique_ptr<cv::VideoCapture> cap;
	TrackTower();
	void Lock();
	void Unlock();
	void Stop();
	void Start();
	bool IsRunning();
	virtual ~TrackTower();
};

#endif /* SRC_TRACKTOWER_H_ */

    Status API Training Shop Blog About Pricing

