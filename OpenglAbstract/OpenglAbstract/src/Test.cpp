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
		auto a = 5;
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