#pragma once

#include "ngengine.h"
#include "PhysicsProperty.h"
#include "physics\Physics.h"

namespace ngengine {
	namespace entityProperties {

		PhysicsProperty::PhysicsProperty() :
			velocity(0.0f, 0.0f, 0.0f),
			acceleration(0.0f, 0.0f, 0.0f)
		{
		}

		void PhysicsProperty::setGravity(float gravity)
		{
			acceleration.y = -gravity;
		}

		void PhysicsProperty::update(double deltaTime)
		{
			velocity = physics::Physics::UpdateVelocity(velocity, acceleration, deltaTime);
			node->position = physics::Physics::UpdatePosition(node->position, velocity, deltaTime);
		}

		PhysicsProperty::~PhysicsProperty()
		{
		}
	}
}