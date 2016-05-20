#pragma once

#include <list>
#include <utils\Orientation.h>
#include <utils\Size.h>
#include "glm\glm.hpp"

namespace ngengine {
	namespace physics {

		using utils::Orientation;
		using utils::f_Size3D;

		class PhysicalNode {

		public:
			PhysicalNode();

			void updateBoxPosition();

		public:
			Orientation orientation;
			glm::vec3 position;
			glm::vec3 boxPosition;
			f_Size3D size;
		};
	}
}