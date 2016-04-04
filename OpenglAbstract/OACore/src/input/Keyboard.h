#pragma once

#include "Dependencies\GLEW\include\GL\glew.h"
#include "Dependencies\GLFW\include\GLFW\glfw3.h"

namespace ngengine {
	namespace input {
		enum class KeyState: unsigned int
		{
			Pressed = GLFW_PRESS,
			Released = GLFW_RELEASE
		};

		class Keyboard
		{
		public:
			Keyboard() : keysState{ KeyState::Released } { };
			~Keyboard();

		public:
			KeyState getKeyState(int keyIdentifier) const;
			void keyboardCallback(int keyIdentifier, int action);

		private:
			std::array<KeyState, 1024> keysState;
		};
	}
}


