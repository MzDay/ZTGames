#pragma once

namespace ngengine {
	namespace utils {
		struct Size1D {
			int width;
		};

		struct Size2D {
			int width;
			int height;
		};

		struct Size3D {
			int width;
			int height;
			int depth;
		};

		struct f_Size3D {
			float width;
			float height;
			float depth;

			f_Size3D() : width(0), height(0), depth(0) {}
			f_Size3D(float width, float height, float depth) : width(width), height(height), depth(depth) {}
		};
	}
}