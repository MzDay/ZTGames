#pragma once

#include <ztengine.h>
#include "entityProperties\PhysicsProperty.h"
#include "scene\Camera.h"
#include "input\InputManager.h"
#include "input\Keyboard.h"
#include "utils\Position.h"

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

private:
	void updateInput(float deltaTime);
	void handleMouseInput(double x, double y);

public:
	Camera camera;
	PhysicsProperty physics;
	InputManager* input;

private:
	Pos2D lastMousePos;
	bool isFirstMouse;
};

