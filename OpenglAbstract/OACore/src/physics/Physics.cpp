#include "ngengine.h"
#include "Physics.h"

namespace ngengine {
	namespace physics {

		glm::vec3 Physics::UpdatePosition(glm::vec3 position, glm::vec3 velocity)
		{
			return position + velocity;
		}

		glm::vec3 Physics::UpdateVelocity(glm::vec3 velocity, glm::vec3 acceleration) 
		{
			return velocity + acceleration;
		}
	}
}