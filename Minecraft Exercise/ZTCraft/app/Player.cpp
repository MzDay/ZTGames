#include "Player.h"

Player::Player()
{
	physics.replaceNode(camera.getNode());
	physics.node->size.depth = 1;
	physics.node->size.width = 1;
	physics.node->size.height= 1;
}

void Player::Update(float deltaTime)
{
	updateInput(deltaTime);

	physics.updateVelocity(deltaTime);
	physics.addMovementToVelocity(deltaTime);

	physics.collisionsWithStaticObjects(*worldBlocksNodes);

	physics.update(deltaTime);
	camera.update();
}

void Player::SetInputManager(InputManager& inputManager)
{
	input = &inputManager;
	input->setUserMouseCallback(std::bind(&Player::handleMouseInput, this, std::placeholders::_1,
		std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void Player::setWorldPointer(std::vector<PhysicalNode>& blocksNodes)
{
	worldBlocksNodes = &blocksNodes;
}

void Player::updateInput(float deltaTime)
{
	 static const float cSpeed = 0.008f;

	if (input == nullptr) { 
		return;
	}

	if (input->getKeyState(GLFW_KEY_W) == KeyState::Pressed) {
		physics.addToMovement(
		camera.getMovementRelativeToCameraPlaneAndLookAt(glm::vec3(0.0f, 0.0f, cSpeed)));
	}
	if (input->getKeyState(GLFW_KEY_S) == KeyState::Pressed) {
		physics.addToMovement(
			camera.getMovementRelativeToCameraPlaneAndLookAt(glm::vec3(0.0f, 0.0f, -cSpeed)));
	}
	if (input->getKeyState(GLFW_KEY_D) == KeyState::Pressed) {
		physics.addToMovement(
			camera.getMovementRelativeToCameraPlaneAndLookAt(glm::vec3(cSpeed, 0.0f, 0.0f)));
	}
	if (input->getKeyState(GLFW_KEY_A) == KeyState::Pressed) {
		physics.addToMovement(
			camera.getMovementRelativeToCameraPlaneAndLookAt(glm::vec3(-cSpeed, 0.0f, 0.0f)));
	}
	if (input->getKeyState(GLFW_KEY_SPACE) == KeyState::Pressed) {
		physics.addToMovement((glm::vec3(0.0f, cSpeed, 0.0f)));
	}
	if (input->getKeyState(GLFW_KEY_LEFT_SHIFT) == KeyState::Pressed) {
		physics.addToMovement((glm::vec3(0.0f, -cSpeed, 0.0f)));
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