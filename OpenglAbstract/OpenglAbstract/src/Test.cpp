#include "../include/Application.h"
#include <iostream>
#include <limits>

class Game : public Application
{
public:
	void startup() {

	}
	void shutdown() {

	}
	void render(double t) {
		const GLfloat green[] = { 0.0f, 0.25f, 0.0f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, green);
	}
	void update(double t) {

	}
};

int main() {
	Game game;

	game.run();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}