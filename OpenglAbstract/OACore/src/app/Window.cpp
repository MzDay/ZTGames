#include "ngengine.h"
#include "Window.h"

namespace ngengine {
	namespace app {

		Window::Window(const std::string& title, utils::Size2D size) :
			windowTitle(title), windowSize(size), windowHandle(nullptr) {
		}

		Window::~Window() {
			glfwDestroyWindow(windowHandle);
		}

		void Window::createWindow() {
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			windowHandle = glfwCreateWindow(windowSize.width, windowSize.height, windowTitle.c_str(), nullptr, nullptr);

			// First hide the window
			glfwHideWindow(windowHandle);

			glfwSetWindowSizeCallback(windowHandle, onResizeCallback);
		}

		void Window::showWindow() {
			glfwShowWindow(windowHandle);
		}

		void Window::makeContext() {
			if (windowHandle != nullptr) {
				glfwMakeContextCurrent(windowHandle);
			}
			// TODO: Maybe throw exception
		}

		void Window::setTitle(const std::string& title) {
			windowTitle = title;
			glfwSetWindowTitle(windowHandle, title.c_str());
		}

		float Window::getWindowRatio()
		{
			return windowSize.width / windowSize.height;
		}

		void Window::updateWindow() {
			// TODO: Check if we can avoid using glClear here and let the user decide
			glClear(GL_DEPTH);
			glfwPollEvents();
			glfwSwapBuffers(windowHandle);
		}

		utils::Size2D Window::getSize()
		{
			glfwGetWindowSize(windowHandle, &(windowSize.width), &windowSize.height);

			return windowSize;
		}

		void Window::attachKeyCallback(std::function<void(GLFWwindow*, int, int, int, int)> callback)
		{
			GLFWkeyfun* ptr = callback.target<GLFWkeyfun>();

			glfwSetKeyCallback(windowHandle, *ptr);
		}

		void Window::onResizeCallback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);

			// TODO: Maybe give the user access to know when the window has changed by using glfwGetWindowUserPointer to (this)
		}
	}
}