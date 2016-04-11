#include "ngengine.h"
#include "Physics.h"

namespace ngengine {
	namespace physics {

		glm::vec3 Physics::updatePosition(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration, float deltaTime)
		{
			glm::vec3 updatedVelocity = velocity + acceleration;

			return position + (updatedVelocity * deltaTime);
		}
	}
}