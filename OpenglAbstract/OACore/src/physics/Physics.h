#pragma once

#include "glm\glm.hpp"

namespace ngengine {
	namespace physics {

		class Physics {

		public:
			static glm::vec3 UpdatePosition(glm::vec3 position, glm::vec3 velocity, float deltaTime);
			static glm::vec3 UpdateVelocity(glm::vec3 velocity, glm::vec3 acceleration, float deltaTime);
		};
	}
}