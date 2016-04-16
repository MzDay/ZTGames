#include "ngengine.h"
#include "Mouse.h"

namespace ngengine {
	namespace input {

		Mouse::Mouse()
		{
			isFirstMouse = true;
		}

		Pos2D Mouse::getMousePosition(GLFWwindow* window)
		{
			Pos2D mousePoistion;

			glfwGetCursorPos(window, &mousePoistion.x, &mousePoistion.y);

			return mousePoistion;
		}

		Pos2D Mouse::getNormalizedMousePosition(GLFWwindow* window, Size2D windowSize)
		{
			Pos2D mousePoistion = getMousePosition(window);
			Pos2D normalizedPoistion;

			normalizedPoistion.x = -1.0 + 2.0 * mousePoistion.x / windowSize.width;
			normalizedPoistion.y = -(-1.0 + 2.0 * mousePoistion.y / windowSize.height);

			return normalizedPoistion;
		}

		void Mouse::setUserMouseCallback(std::function<void(double oldX, double oldY, double newX, double newY)> callback)
		{
			userMouseCallback = callback;
		}

		void Mouse::mouseCallback(double x, double y)
		{
			if (isFirstMouse)
			{
				lastMousePos.x = x;
				lastMousePos.y = y;
				isFirstMouse = false;
			}

			if (userMouseCallback != nullptr)
			{
				userMouseCallback(lastMousePos.x, lastMousePos.y, x, y);
			}

			lastMousePos.x = x;
			lastMousePos.y = y;
		}

		Mouse::~Mouse()
		{
		}

	}
}
