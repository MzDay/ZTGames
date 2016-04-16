#include "Player.h"

Player::Player()
{
	physics.replaceNode(camera.getNode());
}

void Player::Update(float deltaTime)
{
	physics.update(deltaTime);
	updateInput(deltaTime);
	camera.update();
}

void Player::SetInputManager(InputManager& inputManager)
{
	input = &inputManager;
	input->setUserMouseCallback(std::bind(&Player::handleMouseInput, this, std::placeholders::_1,
		std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void Player::updateInput(float deltaTime)
{
	if (input == nullptr) { 
		return;
	}

	if (input->getKeyState(GLFW_KEY_W) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(0.0f, 0.0f, 0.02f * deltaTime));
	}
	if (input->getKeyState(GLFW_KEY_S) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(0.0f, 0.0f, -0.02f * deltaTime));
	}
	if (input->getKeyState(GLFW_KEY_D) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(0.02f * deltaTime, 0.0f, 0.0f));
	}
	if (input->getKeyState(GLFW_KEY_A) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(-0.02f * deltaTime, 0.0f, 0.0f));
	}
}

void Player::handleMouseInput(double oldX, double oldY, double newX, double newY)
{
	GLfloat xoffset = newX - oldX;
	GLfloat yoffset = oldY - newY;

	GLfloat sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	camera.addToPitchInRange(yoffset, 89.0f, -89.0f);
	camera.addToYaw(xoffset);
}

Player::~Player()
{
}