#include "Time.h"
#include <stdio.h>


Time* Time::instance = nullptr;

Time* Time::GetInstance() {
	if (instance == nullptr)
		instance = new Time();

	return instance;
}

void Time::setTime() {  
	startTime = stopTime;
	stopTime = std::chrono::steady_clock::now();
}

Time::Time() {
	startTime = std::chrono::steady_clock::now();
	stopTime = std::chrono::steady_clock::now();
	FixedTime = std::chrono::steady_clock::now();
}

double Time::getDeltaTime() {
	return (double)std::chrono::duration_cast<std::chrono::microseconds>(GetInstance()->stopTime - GetInstance()->startTime).count()/(1000000);
}

bool Time::isFixedTime() {
	if ( (std::chrono::steady_clock::now() - FixedTime + std::chrono::microseconds(1000000 / FIXED_UPDATE_FPS)).count() > 0) {
		FixedTime += std::chrono::microseconds(1000000 / FIXED_UPDATE_FPS);
		return true;
	}
	return false;
}