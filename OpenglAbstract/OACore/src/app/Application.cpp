#include "ngengine.h"
#include "Application.h"

namespace ngengine {
	namespace app{
		Application::Application(const string& title, const Size2D size) : window(title, size){
			if (!glfwInit()) {
				//TODO: Log error
				std::cerr << "GLFW failed to init" << std::endl;
			}

			window.createWindow();

			// Make the window context current
			window.makeContext();

			// We initialize the GLEW to make opengl function work
			if (glewInit() != GLEW_OK) {
				std::cerr << "GLEW failed to init" << std::endl;
			}

			inputManager.setWindow(std::move(window));
		}

		void Application::run(){
			window.showWindow();

			// Use the startup function that the user defined (if he had)
			startup();

			while (!window.shouldClose()) {
				update(timer.getDelta());
				render(timer.getDelta());

				window.updateWindow();
			}
		}

		Application::~Application() {
			// TODO: Delete every allocated memory
			shutdown();
			glfwTerminate();
		}
	}
}