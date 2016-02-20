#include "Game.h"

void Game::startup() {
	
}

void Game::update(double time) {

}

void Game::render(double time) {
	float r = static_cast<float>(std::sin(time));
	float g = static_cast<float>(std::cos(time));
	float b = static_cast<float>(std::sin(time));
	
	logger.logInfo("Red:   " + std::to_string(r));
	logger.logInfo("Green: " + std::to_string(g));
	logger.logInfo("Blue:  " + std::to_string(b));

	GLfloat black[] = { r, g, b, 0.0f };
	glClearBufferfv(GL_COLOR, 0, black);
}

void Game::userCallback() {

}

void Game::shutdown() {

}