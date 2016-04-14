#include "Player.h"



Player::Player()
{
	physics.setGravity(0.01);
}

void Player::Update(float deltaTime)
{
	physics.update(deltaTime);
	camera.setPosition(physics.position);
	camera.update();
}

Camera Player::getCamera() const
{
	return camera;
}

Player::~Player()
{
}