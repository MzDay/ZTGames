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
			inline bool shouldClose() const { return glfwWindowShouldClose(m_Window) != 0; };
			void updateWindow();
			utils::Size2D getSize();
			void attachWindowPointer(void*);
			void attachKeyCallback(std::function<void(GLFWwindow*, int, int, int, int)>);

		public:
			void setTitle(const std::string&);
			std::tuple<double, double> getMousePos();

		private:
			static void _onResizeCallback(GLFWwindow*, int, int);

		private:
			std::string m_Title;
			utils::Size2D m_Size;
			GLFWwindow* m_Window;
		};
	}
}