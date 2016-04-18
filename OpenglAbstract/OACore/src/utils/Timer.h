#pragma once

#include "ngengine.h"

namespace ngengine {
	namespace utils {
		using std::chrono::high_resolution_clock;
		using std::chrono::duration;
		using std::chrono::time_point;
		using std::chrono::duration_cast;

		typedef std::chrono::duration<float> fsec;

		class Timer
		{
		public:
			Timer()
				: timePrev(high_resolution_clock::now()),
				firstStart(high_resolution_clock::now())
			{
			}

			float getDelta()
			{
				 // TODO: Fix delta time because either it doesn't return the right value
				 //		  or we use it wrong!
				auto timeCurrent = high_resolution_clock::now();

				fsec d = timeCurrent - timePrev;

				//duration<float, std::milli> delta(timeCurrent - timePrev);
				float delta = duration_cast<std::chrono::milliseconds>(d).count();

				timePrev = timeCurrent;

				return delta;
			}

			float getPassedTime() {
				auto timeCurrent = high_resolution_clock::now();

				duration< float > delta(timeCurrent - firstStart);

				return delta.count();
			}

		private:
			time_point<high_resolution_clock> timePrev;
			time_point<high_resolution_clock> firstStart;
		};

	}
}