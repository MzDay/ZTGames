#include "Player.h"



Player::Player()
{
	physics.setGravity(0.00001);
}

void Player::Update(float deltaTime)
{
	physics.update(deltaTime);
	camera.setPosition(physics.position);
	camera.update();
}

Player::~Player()
{
}