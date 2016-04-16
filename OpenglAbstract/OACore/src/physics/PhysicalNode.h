#pragma once

#include <list>
#include <utils\Orientation.h>
#include "glm\glm.hpp"

namespace ngengine {
	namespace physics {

		using utils::Orientation;

		class PhysicalNode {

		public:
			PhysicalNode();

		public:
			Orientation orientation;
			glm::vec3 position;
		};
	}
}