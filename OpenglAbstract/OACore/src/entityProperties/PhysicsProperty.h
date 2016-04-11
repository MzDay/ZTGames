#pragma once

#include "IEntityProperty.h"
#include "glm\glm.hpp"

namespace ngengine {
	namespace entityProperties {

		class PhysicsProperty : public IEntityProperty {

		public:
			PhysicsProperty();
			~PhysicsProperty();

			void setGravity(float gravity);
			void update(double deltaTime);

		public:
			glm::vec3 position;
			glm::vec3 velocity;
			glm::vec3 acceleration;
		};
	}
}