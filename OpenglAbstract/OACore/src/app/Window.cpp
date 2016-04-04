#include "ngengine.h"
#include "Window.h"

namespace ngengine {
	namespace app {

		Window::Window(const std::string& title, utils::Size2D size) :
			windowTitle(title), windowSize(size), windowHandler(nullptr){
		}

		Window::~Window() {
			glfwDestroyWindow(windowHandler);
		}

		void Window::createWindow() {
			windowHandler = glfwCreateWindow(windowSize.width, windowSize.height, windowTitle.c_str(), nullptr, nullptr);

			// First hide the window
			glfwHideWindow(windowHandler);

			glfwSetWindowSizeCallback(windowHandler, onResizeCallback);
		}

		void Window::showWindow() {
			glfwShowWindow(windowHandler);
		}

		void Window::makeContext() {
			if (windowHandler != nullptr) {
				glfwMakeContextCurrent(windowHandler);
			}
			// TODO: Maybe throw exception
		}

		void Window::setTitle(const std::string& title) {
			windowTitle = title;
			glfwSetWindowTitle(windowHandler, title.c_str());
		}

		void Window::updateWindow() {
			// TODO: Check if we can avoid using glClear here and let the user decide
			glClear(GL_DEPTH);
			glfwPollEvents();
			glfwSwapBuffers(windowHandler);
		}

		utils::Size2D Window::getSize()
		{
			glfwGetWindowSize(windowHandler, &(windowSize.width), &windowSize.height);

			return windowSize;
		}

		void Window::attachKeyCallback(std::function<void(GLFWwindow*, int, int, int, int)> callback)
		{
			GLFWkeyfun* ptr = callback.target<GLFWkeyfun>();

			glfwSetKeyCallback(windowHandler, *ptr);
		}

		void Window::onResizeCallback(GLFWwindow* window, int width, int height) {
			// TODO: Maybe give the user access to know when the window has changed by using glfwGetWindowUserPointer to (this)
			glViewport(0, 0, width, height);
		}
	}
}