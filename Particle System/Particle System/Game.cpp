#include "Game.h"
#include <cmath>
#include <iomanip>
#include <thread>

using namespace std::literals;

void Game::startup() {
}

void Game::update(double time) {

}

void Game::render(double time) {

	float r = static_cast<float>(std::sin(time)) * 0.5f;
	float g = static_cast<float>(std::cos(time)) * 0.6f;
	float b = static_cast<float>(std::sin(time)) * 0.5f;
	
	logger.logSuccess("Red:   " + std::to_string(r));
	logger.logWarning("Green: " + std::to_string(g));
	logger.logError("Blue:  " + std::to_string(b));
	logger.logInfo("Red:   " + std::to_string(r));
	logger.logSimple("Green: " + std::to_string(g));

	GLfloat black[] = { r, g, b, 0.0f };
	glClearBufferfv(GL_COLOR, 0, black);
}

void Game::userCallback() {

}