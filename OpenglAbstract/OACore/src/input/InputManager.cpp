#include "ngengine.h"
#include "InputManager.h"

namespace ngengine {
	namespace input {

		InputManager::InputManager()
		{
		}

		void InputManager::setWindow(Window&& parentWindow) {
			window = &parentWindow;

			glfwSetWindowUserPointer(window->getHandler(), this);

			glfwSetKeyCallback(window->getHandler(), keyboardCallback);
		}

		Pos2D InputManager::getMousePosition()
		{
			return mouse.getMousePosition(window->getHandler());
		}

		Pos2D InputManager::getNormalizedMousePosition()
		{
			return mouse.getNormalizedMousePosition(window->getHandler(), window->getSize());
		}

		KeyState InputManager::getKeyState(int keyIdentifier)
		{
			return keyboard.getKeyState(keyIdentifier);
		}

		void InputManager::setKeyState(int keyIdentifier, KeyState keyState)
		{
			keyboard.setKeyState(keyIdentifier, keyState);
		}

		void InputManager::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
		{
			KeyState keyState = (action == GLFW_RELEASE) ? KeyState::Released : KeyState::Pressed;

			InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
			inputManager->setKeyState(key, keyState);
		}

		InputManager::~InputManager()
		{
		}
	}
}