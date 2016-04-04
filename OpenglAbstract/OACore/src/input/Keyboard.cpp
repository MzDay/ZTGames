#include "ngengine.h"
#include "Keyboard.h"

namespace ngengine {
	namespace input {

		KeyState Keyboard::getKeyState(int keyIdentifier) const
		{
			return keysState[keyIdentifier];
		}

		void Keyboard::keyboardCallback(int keyIdentifier, int action)
		{
			KeyState keyState = (action == GLFW_RELEASE) ? KeyState::Released : KeyState::Pressed;
			keysState[keyIdentifier] = keyState;
		}

		Keyboard::~Keyboard()
		{
		}
	}
}