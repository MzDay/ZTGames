#pragma once

#include "app\Window.h"
#include "utils\Position.h"
#include "utils\Size.h"

namespace ngengine {
	namespace input {

		using utils::Pos2D;
		using utils::Size2D;

		class Mouse
		{
		public:
			Mouse();
			~Mouse();

			void setUserMouseCallback(std::function<void(double oldX, double oldY, double newX, double newY)> callback);
			void mouseCallback(double x, double y);

		public:
			Pos2D getMousePosition(GLFWwindow* window);
			Pos2D getNormalizedMousePosition(GLFWwindow* window, Size2D windowSize);

		private:
			std::function<void(double oldX, double oldY, double newX, double newY)>  userMouseCallback;
			Pos2D lastMousePos;
			bool isFirstMouse;
		};
	}
}