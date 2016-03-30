#pragma once

#include "app\Window.h"
#include "utils\Size.h"
#include "input\Keyboard.h"
#include "input\Mouse.h"

namespace ngengine {
	namespace input {

		using utils::Pos2D;
		using app::Window;

		class InputManager
		{
		public:
			InputManager();
			~InputManager();

		public:
			void setWindow(Window&& window);

		public:
			Pos2D getMousePosition();
			Pos2D getNormalizedMousePosition();
			KeyState getKeyState(int keyIdentifier);
			void setKeyState(int keyIdentifier, KeyState keyState);

		private:
			static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

		private:
			Window* window;
			Keyboard keyboard;
			Mouse mouse;
		};
	}
}