#pragma once

#include <ztengine.h>
#include "entityProperties\PhysicsProperty.h"

using ngengine::entityProperties::PhysicsProperty;

class Player
{

public:
	Player();
	~Player();

private:
	PhysicsProperty physics;
};

