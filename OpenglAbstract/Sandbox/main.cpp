#include <iostream>
#include "app\Application.h"
#include "utils\Timer.h"

class Game : public ngengine::app::Application
{
	NG_ENGINE_BASE;

	void startup() {
		counter = 0;
		prevTime = 0;
	}

	void update(double) {
		counter++;
		if (timer.getPassedTime() - prevTime >= 1) {
			setTitle("FPS: " + std::to_string(counter));
			counter = 0;
			prevTime = timer.getPassedTime();
		}
	}

	void render(double) {
		static const GLfloat color[] = { 0.2f, 0.4f, 0.8f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, color);
	}

	int counter;
	int prevTime;
	ngengine::utils::Timer timer;
};

int main() {
	Game game("Naor");
	game.run();

	return 0;
}