#pragma once

#include "ngengine.h"
#include "PhysicsProperty.h"
#include "physics\Physics.h"

namespace ngengine {
	namespace entityProperties {

		PhysicsProperty::PhysicsProperty() :
			position(0.0f, 0.0f, 0.0f),
			velocity(0.0f, 0.0f, 0.0f),
			acceleration(0.0f, 0.0f, 0.0f)
		{
		}

		void PhysicsProperty::setGravity(float gravity)
		{
			acceleration.y = gravity;
		}

		void PhysicsProperty::update(double deltaTime)
		{
			position = physics::Physics::updatePosition(position, velocity, acceleration, deltaTime);
		}

		PhysicsProperty::~PhysicsProperty()
		{
		}
	}
}