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

		public:
			Pos2D getMousePosition(GLFWwindow* window);
			Pos2D getNormalizedMousePosition(GLFWwindow* window, Size2D windowSize);
		};
	}
}