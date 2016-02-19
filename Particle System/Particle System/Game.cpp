#include "Game.h"
#include <cmath>
#include <iomanip>

template<typename T> void printElement(T t, const int& width)
{
	std::cout << std::left << std::setw(width) << std::setfill(' ') << t;
}

void Game::startup() {

}

void Game::update(double time) {

}

void Game::render(double time) {

	float r = static_cast<float>(std::sin(time)) * 0.5f;
	float g = static_cast<float>(std::cos(time)) * 0.6f;
	float b = static_cast<float>(std::sin(time)) * 0.5f;
	
	printElement(r, 15);
	printElement(g, 15);
	printElement(b, 15);
	std::cout << '\n';

	GLfloat black[] = { r, g, b, 0.0f };
	glClearBufferfv(GL_COLOR, 0, black);
}

void Game::userCallback() {

}