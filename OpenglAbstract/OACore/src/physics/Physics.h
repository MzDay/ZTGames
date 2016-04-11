#pragma once

#include "glm\glm.hpp"

namespace ngengine {
	namespace physics {

		class Physics {

		public:
			static glm::vec3 updatePosition(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration, float deltaTime);
		};
	}
}