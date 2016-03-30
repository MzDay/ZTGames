#include "ngengine.h"
#include "Mouse.h"

namespace ngengine {
	namespace input {

		Mouse::Mouse()
		{
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
			normalizedPoistion.x = -(-1.0 + 2.0 * mousePoistion.y / windowSize.height);

			return normalizedPoistion;
		}

		Mouse::~Mouse()
		{
		}
	}
}
