#ifndef OA_TIMER_H
#define OA_TIMER_H

#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::time_point;

class Timer
{
public:
	Timer()
		: timePrev(high_resolution_clock::now()),
		  firstStart(high_resolution_clock::now())
	{
	}

	double getDelta()
	{
		auto timeCurrent = high_resolution_clock::now();

		duration< double > delta(timeCurrent - timePrev);

		timePrev = high_resolution_clock::now();

		return delta.count();
	}

	double getPassedTime() {
		auto timeCurrent = high_resolution_clock::now();

		duration< double > delta(timeCurrent - firstStart);

		return delta.count();
	}

private:
	time_point<high_resolution_clock> timePrev;
	time_point<high_resolution_clock> firstStart;
};

#endif