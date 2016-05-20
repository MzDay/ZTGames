#pragma once

#include <ztengine.h>
#include "entityProperties\PhysicsProperty.h"
#include "scene\Camera.h"
#include "input\InputManager.h"
#include "input\Keyboard.h"
#include "utils\Position.h"

using ngengine::physics::PhysicalNode;
using ngengine::entityProperties::PhysicsProperty;
using ngengine::scene::Camera;
using ngengine::input::InputManager;
using ngengine::input::KeyState;
using ngengine::utils::Pos2D;

class Player
{

public:
	Player();
	~Player();

	void Update(float deltaTime);
	void SetInputManager(InputManager& inputManager);

	void setWorldPointer(std::vector<PhysicalNode>& blocksNodes);

private:
	void updateInput(float deltaTime);
	void handleMouseInput(double oldX, double oldY, double newX, double newY);

	std::vector<PhysicalNode>* worldBlocksNodes;

public:
	Camera camera;
	PhysicsProperty physics;
	InputManager* input;
};

