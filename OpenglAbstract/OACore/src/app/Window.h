#pragma once

#include "utils\Size.h"
#include "Dependencies\GLEW\include\GL\glew.h"
#include "Dependencies\GLFW\include\GLFW\glfw3.h"

namespace ngengine {
	namespace app {

		class Window {
		public:
			Window(const std::string&, utils::Size2D);
			~Window();

		public:
			void createWindow();
			void makeContext();
			inline bool shouldClose() const { return glfwWindowShouldClose(windowHandler) != 0; };
			void updateWindow();
			void showWindow();

		public:
			GLFWwindow* getHandler() const { return windowHandler; }

			utils::Size2D getSize();

			inline std::string getTitle() const { return windowTitle; }
			void setTitle(const std::string&);

		private:
			static void onResizeCallback(GLFWwindow*, int, int);
			void attachKeyCallback(std::function<void(GLFWwindow*, int, int, int, int)> callback);

		private:
			std::string windowTitle;
			utils::Size2D windowSize;
			GLFWwindow* windowHandler;
		};
	}
}