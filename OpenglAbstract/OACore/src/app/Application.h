#pragma once

#include "ngengine.h"
#include "utils\Size.h"
#include "utils\Timer.h"
#include "Window.h"
#include "input\InputManager.h"
#include "Dependencies\GLEW\include\GL\glew.h"
#include "Dependencies\GLFW\include\GLFW\glfw3.h"

#define NG_ENGINE_BASE using Application::Application

namespace ngengine {
	namespace app {

		using utils::Size2D;
		using input::InputManager;
		using std::string;
		using utils::Timer;

		constexpr Size2D DEFAULT_SIZE = Size2D({ 640, 480 });

		constexpr char DEFAULT_TITLE[] = "Opengl Abstract - Made By Naor & Guy";

		class Application {
		public:
			Application(const string&, const Size2D);
			Application(const string& title, int width, int height) : Application(title, Size2D{ width, height }) {}
			Application(const string& title) : Application(title, DEFAULT_SIZE) {}
			Application(const Size2D size) : Application(DEFAULT_TITLE, size) {}
			Application(int width, int height) : Application(DEFAULT_TITLE, Size2D{ width, height }) {}
			Application() : Application(DEFAULT_TITLE, DEFAULT_SIZE) {}

			virtual ~Application();

		public:
			virtual void run() final;

		protected:
			virtual void render(double) {};
			virtual void update(double) {};
			virtual void startup() {};
			virtual void shutdown() {};

		public:
			Window window;
			InputManager inputManager;

		private:
			 Timer timer;
		};
	}
}