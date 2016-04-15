#include "Player.h"

Player::Player()
{
	lastMousePos.x = 400;
	lastMousePos.y = 300;
	isFirstMouse = true;
}

void Player::Update(float deltaTime)
{
	// Should be affected by physics first
	physics.update(deltaTime);
	camera.setPosition(physics.position);

	// Then updated by the player
	updateInput(deltaTime);
	physics.position = camera.getPosition();

	// Update the camera in the end
	camera.update();
}

void Player::SetInputManager(InputManager& inputManager)
{
	input = &inputManager;
	(*input).setUserMouseCallback(std::bind(&Player::handleMouseInput, this, std::placeholders::_1,
		std::placeholders::_2));
}

void Player::updateInput(float deltaTime)
{
	if (input == nullptr) { 
		return;
	}

	if ((*input).getKeyState(GLFW_KEY_W) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(0.0f, 0.0f, 0.02f * deltaTime));
	}
	if ((*input).getKeyState(GLFW_KEY_S) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(0.0f, 0.0f, -0.02f * deltaTime));
	}
	if ((*input).getKeyState(GLFW_KEY_D) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(0.02f * deltaTime, 0.0f, 0.0f));
	}
	if ((*input).getKeyState(GLFW_KEY_A) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(-0.02f * deltaTime, 0.0f, 0.0f));
	}
}

void Player::handleMouseInput(double x, double y)
{
	if (isFirstMouse)
	{
		lastMousePos.x = x;
		lastMousePos.y = y;
		isFirstMouse = false;
	}

	GLfloat xoffset = x - lastMousePos.x;
	GLfloat yoffset = lastMousePos.y - y;
	lastMousePos.x = x;
	lastMousePos.y = y;

	GLfloat sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	camera.addToPitchInRange(yoffset, 89.0f, -89.0f);
	camera.addToYaw(xoffset);
}


Player::~Player()
{
}