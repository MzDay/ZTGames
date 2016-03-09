#ifndef OA_APPLICATION_H
#define OA_APPLICATION_H

#include <SDL.h>
#include <string>
#include "Models\Size.h"
#include "Window.h"
#include "../include/Common/Timer.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#undef main

using std::string;

constexpr Size2D DEFAULT_SIZE =  Size2D({ 640, 480 });

constexpr char DEFAULT_TITLE[] = "Opengl Abstract - Made By Naor & Guy";


class Application {
public:
	Application(const string&, const Size2D);
	Application(const string& title, int width, int height) : Application(title, Size2D{ width, height }) {}
	Application(const string& title) : Application(title, DEFAULT_SIZE) {}
	Application(const Size2D size) : Application(DEFAULT_TITLE, size) {}
	Application(int width, int height) : Application(DEFAULT_TITLE, Size2D({ width, height })) {}
	Application() : Application(DEFAULT_TITLE, DEFAULT_SIZE) {}

	~Application();

public:
	virtual void run() final;

public:
	const string& getTitle() const { return title; }
	const Size2D& getWindowSize() const { return windowSize; }

public:
	virtual void render(double) {};
	virtual void update(double) {};
	virtual void startup() {};
	virtual void shutdown() {};

private:
	string title;
	Size2D windowSize;
	Window* window;
	bool shouldQuit;
};

#endif