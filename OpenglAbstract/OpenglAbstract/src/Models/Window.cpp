#include "../../include/Window.h"

Window::Window(const std::string& title, Size2D size) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, size.width, size.height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		throw std::invalid_argument("[SDL] Could not create a window");
	}
}

Window::~Window() {
	SDL_DestroyWindow(window);
	window = nullptr;
}

void Window::swapWindow() {
	SDL_GL_SwapWindow(window);
}