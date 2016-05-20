#pragma once

#include "IEntityProperty.h"
#include "physics\PhysicalEntity.h"
#include "physics\PhysicalNode.h"
#include "glm\glm.hpp"

namespace ngengine {
	namespace entityProperties {

		using physics::PhysicalNode;

		class PhysicsProperty : public IEntityProperty, public physics::PhysicalEntity {

		public:
			PhysicsProperty();
			~PhysicsProperty();

			void setGravity(float gravity);
			void updateVelocity(float deltaTime);
			virtual void update(float deltaTime) override;

			void addToMovement(glm::vec3 movement);
			void addMovementToVelocity(float deltaTime);
			void collisionsWithStaticObjects(std::vector<PhysicalNode> nodes);

		private:
			void handleCollisionsWithStaticObjects(std::vector<PhysicalNode> nodes, float& timeRemaining);
			float checkCollisionTimePerAxis(PhysicalNode node1, PhysicalNode node2, float& normalx, float& normaly, float& normalz);
			PhysicalNode GetSweptBroadphaseNode(PhysicalNode node);
			bool AABBCheck(PhysicalNode b1, PhysicalNode b2);

		public:
			glm::vec3 velocity;
			glm::vec3 acceleration;
			glm::vec3 movementToAdd;

		private:
			glm::vec3 velocityWithoutMovement;
		};
	}
}