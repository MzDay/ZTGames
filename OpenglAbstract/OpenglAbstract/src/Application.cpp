#include "../include/Application.h"

Application::Application(const string& title, const Size2D size) {
	Application& self = (*this);

	self.title = title;
	self.windowSize = size;
	self.shouldQuit = false;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::invalid_argument("[SDL] Could not initialize SDL2");
	}
}

void Application::run() {
	try {
		window = new Window(title, windowSize);
	}
	catch (std::invalid_argument ex) {
		// TODO: Error message for the user
	}

	if (glewInit()) {
		// TODO: Throw an appropriate exception
	}

	startup();
	
	Timer timer;

	SDL_Event e;

	while (!shouldQuit) {
		while (SDL_PollEvent(&e)) {

		}
		// TODO: Add while loop for input class
		update(timer.getDelta());
		render(timer.getDelta());

		window->swapWindow();
	}

	shutdown();

}

Application::~Application() {
	delete window;

	SDL_Quit();
}
