#pragma once

namespace ngengine {
	namespace utils {
		struct Orientation {
			float yaw;
			float pitch;
			float roll;

			Orientation() : yaw(0), pitch(0), roll(0) {}
			Orientation(float yaw, float pitch, float roll) : yaw(yaw), pitch(pitch), roll(roll) {}
		};
	}
}