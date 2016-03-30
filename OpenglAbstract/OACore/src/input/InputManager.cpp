#include "ngengine.h"
#include "InputManager.h"

namespace ngengine {
	namespace input {

		InputManager::InputManager()
		{
		}

		InputManager::InputManager(Window parentWindow)
		{
			window = &parentWindow;

			GLFWkeyfun* ptr = ((std::function<void(GLFWwindow*, int, int, int, int)>)keyboardCallback).target<GLFWkeyfun>();

			glfwSetKeyCallback(window->windowHandler, *ptr);
		}

		Pos2D InputManager::getMousePosition()
		{
			return mouse.getMousePosition(window->windowHandler);
		}

		Pos2D InputManager::getNormalizedMousePosition()
		{
			return mouse.getNormalizedMousePosition(window->windowHandler, window->getSize());
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
			KeyState keyState = (action == GLFW_PRESS) ? KeyState::Pressed : KeyState::Released;

			InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
			inputManager->setKeyState(key, keyState);
		}

		InputManager::~InputManager()
		{
		}
	}
}