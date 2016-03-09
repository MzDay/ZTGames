#include "../../include/Window.h"

Window::Window(const std::string& title, Size2D size) {

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, size.width, size.height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		throw std::invalid_argument("[SDL] Could not create a window");
	}

	context = SDL_GL_CreateContext(window);

	if (context == nullptr) {
		throw std::invalid_argument("[SDL] Could not create OpenGL context");
	}

	SDL_GL_SetSwapInterval(1);
}

Window::~Window() {
	SDL_DestroyWindow(window);
	window = nullptr;
}

void Window::swapWindow() {
	SDL_GL_SwapWindow(window);
}