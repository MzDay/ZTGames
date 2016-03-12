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

		public:
			inline utils::Size2D getSize() const { return m_Size; }
			void setTitle(const std::string&);

		private:
			static void _onResizeCallback(GLFWwindow*, int, int);

		private:
			std::string m_Title;
			utils::Size2D m_Size;
			GLFWwindow* m_Window;
		};
	}
}