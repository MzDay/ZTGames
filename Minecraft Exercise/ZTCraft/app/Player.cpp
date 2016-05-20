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
	 static const float cSpeed = 0.2f;

	if (input == nullptr) { 
		return;
	}

	if (input->getKeyState(GLFW_KEY_W) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(0.0f, 0.0f, cSpeed * deltaTime));
	}
	if (input->getKeyState(GLFW_KEY_S) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(0.0f, 0.0f, -cSpeed * deltaTime));
	}
	if (input->getKeyState(GLFW_KEY_D) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(cSpeed * deltaTime, 0.0f, 0.0f));
	}
	if (input->getKeyState(GLFW_KEY_A) == KeyState::Pressed) {
		camera.addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3(-cSpeed * deltaTime, 0.0f, 0.0f));
	}
	if (input->getKeyState(GLFW_KEY_SPACE) == KeyState::Pressed) {
 		camera.addToPosition(glm::vec3(0.0f, cSpeed * deltaTime, 0.0f));
	}
	if (input->getKeyState(GLFW_KEY_LEFT_CONTROL) == KeyState::Pressed) {
		camera.addToPosition(glm::vec3(0.0f, -cSpeed* deltaTime, 0.0f));
	}
	if (input->getKeyState(GLFW_KEY_ESCAPE) == KeyState::Pressed) {
		 exit(0);
	}
}

void Player::handleMouseInput(double oldX, double oldY, double newX, double newY)
{
	double xoffset = newX - oldX;
	double yoffset = oldY - newY;

	double sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	camera.addToPitchInRange(yoffset, 89.0f, -89.0f);
	camera.addToYaw(xoffset);
}

Player::~Player()
{
}