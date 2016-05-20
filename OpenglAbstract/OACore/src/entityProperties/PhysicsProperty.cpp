#pragma once

#include "ngengine.h"
#include "PhysicsProperty.h"
#include "physics\Physics.h"

namespace ngengine {
	namespace entityProperties {

		PhysicsProperty::PhysicsProperty() :
			velocity(0.0f, 0.0f, 0.0f),
			acceleration(0.0f, 0.0f, 0.0f),
			movementToAdd(0.0f, 0.0f, 0.0f)
		{
		}

		void PhysicsProperty::setGravity(float gravity)
		{
			acceleration.y = -gravity;
		}

		void PhysicsProperty::updateVelocity(float deltaTime)
		{
			velocity = physics::Physics::UpdateVelocity(velocity, acceleration * deltaTime);
		}

		void PhysicsProperty::update(float deltaTime)
		{
			node->position = physics::Physics::UpdatePosition(node->position, velocity);
			movementToAdd -= movementToAdd;
			velocity = velocityWithoutMovement;
		}

		void PhysicsProperty::addToMovement(glm::vec3 movement)
		{
			movementToAdd += movement;
		}

		void PhysicsProperty::addMovementToVelocity(float deltaTime)
		{
			velocityWithoutMovement = velocity;
			velocity += movementToAdd * deltaTime;
		}

		void PhysicsProperty::collisionsWithStaticObjects(std::vector<PhysicalNode> nodes)
		{
			float timeRemainig = 1.0f;

			// One check for any possible axis
			for (int i = 0; i < 3; i++)
			{
				handleCollisionsWithStaticObjects(nodes, timeRemainig);

				if (timeRemainig == 0.0f)
				{
					return;
				}
			}
		}

		void PhysicsProperty::handleCollisionsWithStaticObjects(std::vector<PhysicalNode> nodes, float&  timeRemaining)
		{
			float actualNormalX = 0.0f, actualNormalY = 0.0f, actualNormalZ = 0.0f;
			float tempNormalX = 0.0f, tempNormalY = 0.0f, tempNormalZ = 0.0f;
			float tempCollisionTime = 1.0f, minCollisionTime = 1.0f;
			PhysicalNode broadNode;

			for (int i = 0; i < nodes.size(); i++)
			{
				node->updateBoxPosition();
				nodes[i].updateBoxPosition();

				broadNode = GetSweptBroadphaseNode(*node);

				if (AABBCheck(broadNode, nodes[i])) {
					tempCollisionTime = checkCollisionTimePerAxis(*node, nodes[i], tempNormalX, tempNormalY, tempNormalZ);
				}

				if (tempCollisionTime < minCollisionTime)
				{
					minCollisionTime = tempCollisionTime;
					actualNormalX = tempNormalX;
					actualNormalY = tempNormalY;
					actualNormalZ = tempNormalZ;
				}
			}

			if (minCollisionTime < 1.0f && minCollisionTime <= timeRemaining)
			{
				velocity.x = (actualNormalY + actualNormalZ) * velocity.x * timeRemaining;
				velocity.y = (actualNormalX + actualNormalZ) * velocity.y * timeRemaining;
				velocity.z = (actualNormalX + actualNormalY) * velocity.z * timeRemaining;

				node->position = physics::Physics::UpdatePosition(node->position, velocity);

				timeRemaining -= minCollisionTime;
			}
		}

		float PhysicsProperty::checkCollisionTimePerAxis(PhysicalNode node1, PhysicalNode node2,
			float& normalx, float& normaly, float& normalz)
		{
			float xInvEntry, yInvEntry, zInvEntry;
			float xInvExit, yInvExit, zInvExit;

			// find the distance between the objects on the near and far sides for both x and y
			if (velocity.x > 0.0f)
			{
				xInvEntry = node2.boxPosition.x - (node1.boxPosition.x + node1.size.width);
				xInvExit = (node2.boxPosition.x + node2.size.width) - node1.boxPosition.x;
			}
			else
			{
				xInvEntry = (node2.boxPosition.x + node2.size.width) - node1.boxPosition.x;
				xInvExit = node2.boxPosition.x - (node1.boxPosition.x + node1.size.width);
			}

			if (velocity.y > 0.0f)
			{
				yInvEntry = node2.boxPosition.y - (node1.boxPosition.y + node1.size.height);
				yInvExit = (node2.boxPosition.y + node2.size.height) - node1.boxPosition.y;
			}
			else
			{
				yInvEntry = (node2.boxPosition.y + node2.size.height) - node1.boxPosition.y;
				yInvExit = node2.boxPosition.y - (node2.boxPosition.y + node1.size.height);
			}

			if (velocity.z > 0.0f)
			{
				zInvEntry = node2.boxPosition.z - (node1.boxPosition.z + node1.size.depth);
				zInvExit = (node2.boxPosition.z + node2.size.depth) - node1.boxPosition.z;
			}
			else
			{
				zInvEntry = (node2.boxPosition.z + node2.size.depth) - node1.boxPosition.z;
				zInvExit = node2.boxPosition.z - (node2.boxPosition.z + node1.size.depth);
			}

			// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
			float xEntry, yEntry, zEntry;
			float xExit, yExit, zExit;

			if (velocity.x == 0.0f)
			{
				xEntry = -std::numeric_limits<float>::infinity();
				xExit = std::numeric_limits<float>::infinity();
			}
			else
			{
				xEntry = xInvEntry / velocity.x;
				xExit = xInvExit / velocity.x;
			}

			if (velocity.y == 0.0f)
			{
				yEntry = -std::numeric_limits<float>::infinity();
				yExit = std::numeric_limits<float>::infinity();
			}
			else
			{
				yEntry = yInvEntry / velocity.y;
				yExit = yInvExit / velocity.y;
			}

			if (velocity.z == 0.0f)
			{
				zEntry = -std::numeric_limits<float>::infinity();
				zExit = std::numeric_limits<float>::infinity();
			}
			else
			{
				zEntry = zInvEntry / velocity.z;
				zExit = zInvExit / velocity.z;
			}

			// find the earliest/latest times of collision
			float entryTime = std::max({ xEntry, yEntry, zEntry });
			float exitTime = std::min({ xExit, yExit, zExit });

			// if there was no collision
			if (entryTime > exitTime ||
				xEntry < 0.0f && yEntry < 0.0f && zEntry < 0.0f ||
				xEntry > 1.0f || yEntry > 1.0f || zEntry > 1.0f)
			{
				normalx = 0.0f;
				normaly = 0.0f;
				normalz = 0.0f;
				return 1.0f;
			}

			else // if there was a collision
			{
				// calculate normal of collided surface
				if (xEntry > yEntry && xEntry > zEntry)
				{
					if (xInvEntry < 0.0f)
					{
						normalx = 1.0f;
						normaly = 0.0f;
						normalz = 0.0f;
					}
					else
					{
						normalx = -1.0f;
						normaly = 0.0f;
						normalz = 0.0f;
					}
				}
				else if (yEntry> zEntry)
				{
					if (yInvEntry < 0.0f)
					{
						normalx = 0.0f;
						normaly = 1.0f;
						normalz = 0.0f;
					}
					else
					{
						normalx = 0.0f;
						normaly = -1.0f;
						normalz = 0.0f;
					}
				}
				else
				{
					if (zInvEntry < 0.0f)
					{
						normalx = 0.0f;
						normaly = 0.0f;
						normalz = 1.0f;
					}
					else
					{
						normalx = 0.0f;
						normaly = 0.0f;
						normalz = -1.0f;
					}
				}
			}

			// return the time of collision
			return entryTime;
		}

		PhysicalNode PhysicsProperty::GetSweptBroadphaseNode(PhysicalNode node1)
		{
			PhysicalNode broadNode;

			broadNode.boxPosition.x = velocity.x > 0 ?
				node1.boxPosition.x : node1.boxPosition.x + velocity.x;
			broadNode.boxPosition.y = velocity.y > 0 ?
				node1.boxPosition.y : node1.boxPosition.y + velocity.y;
			broadNode.boxPosition.z = velocity.z > 0 ?
				node1.boxPosition.z : node1.boxPosition.z + velocity.z;

			broadNode.size.width = velocity.x > 0 ?
				velocity.x + node1.size.width : node1.size.width - velocity.x;
			broadNode.size.height = velocity.y > 0 ?
				velocity.y + node1.size.height : node1.size.height - velocity.y;
			broadNode.size.depth = velocity.z > 0 ?
				velocity.z + node1.size.depth : node1.size.depth - velocity.z;

			return broadNode;
		}

		bool PhysicsProperty::AABBCheck(PhysicalNode node1, PhysicalNode node2)
		{
			return !(node1.boxPosition.x + node1.size.width < node2.boxPosition.x ||
				node1.boxPosition.x > node2.boxPosition.x + node1.size.width ||
				node1.boxPosition.y + node1.size.height < node2.boxPosition.y ||
				node1.boxPosition.y > node2.boxPosition.y + node2.size.height ||
				node1.boxPosition.z + node1.size.depth < node2.boxPosition.z ||
				node1.boxPosition.z > node2.boxPosition.z + node2.size.depth);
		}

		PhysicsProperty::~PhysicsProperty()
		{
		}
	}
}