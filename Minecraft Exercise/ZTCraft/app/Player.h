#pragma once

#include <ztengine.h>
#include "entityProperties\PhysicsProperty.h"
#include "scene\Camera.h"

using ngengine::entityProperties::PhysicsProperty;
using ngengine::scene::Camera;

class Player
{

public:
	Player();
	~Player();

	void Update(float deltaTime);

public:
	Camera camera;
	PhysicsProperty physics;
};

