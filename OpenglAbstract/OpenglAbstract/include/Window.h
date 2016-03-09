#ifndef OA_WINDOW_H
#define OA_WINDOW_H

#include <SDL.h>
#include <string>
#include "Models\Size.h"

class Window {
public:
	Window(const std::string&, Size2D);
	~Window();

public:
	void swapWindow();

private:
	SDL_Window* window;
	SDL_GLContext context;
};

#endif