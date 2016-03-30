#include "ngengine.h"
#include "Keyboard.h"

namespace ngengine {
	namespace input {

		KeyState Keyboard::getKeyState(int keyIdentifier)
		{
			return keysState[keyIdentifier];
		}

		void Keyboard::setKeyState(int keyIdentifier, KeyState keyState)
		{
			keysState[keyIdentifier] = keyState;
		}

		void Keyboard::keyboardUpdateCallback(int keyIdentifier, unsigned int glfwAction)
		{
			// TODO: check how to remove the cast
			keysState[keyIdentifier] = static_cast<KeyState> (glfwAction);
		}

		Keyboard::~Keyboard()
		{
		}
	}
}