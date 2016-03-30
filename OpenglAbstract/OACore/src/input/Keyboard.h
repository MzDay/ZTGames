#pragma once

#include <array>
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
			inline Keyboard() { keysState = { KeyState::Released }; };
			~Keyboard();

		public:
			KeyState getKeyState(int keyIdentifier);
			KeyState setKeyState(int keyIdentifier, KeyState keyState);

		private:
			void keyboardUpdateCallback(int keyIdentifier, unsigned int glfwAction);

		private:
			std::array<KeyState, 1024> keysState;
		};
	}
}


