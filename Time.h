#pragma once
#include <chrono>

#define FIXED_UPDATE_FPS (60)

class Time
{
private:
	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point stopTime;
	std::chrono::steady_clock::time_point FixedTime;
	static Time* instance;
	static Time* GetInstance();
	void setTime();
	bool isFixedTime();
	Time();
	friend class Game;
public:
	static double getDeltaTime();
};
 
