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
			// TODO: WE HAVE TO MOVE THIS TO SOME STATIC LOADING CLASS (See page.235) BECAUSE WE CANT
			//		 CREATE STATIC MEMBERS WITHOUT GLEW INIT FIRST! (OpenGL commands)
			if (glewInit() != GLEW_OK) {
				std::cerr << "GLEW failed to init" << std::endl;
				exit(0);
			}
			std::cout << "GLEW Initialized!" << std::endl;

			inputManager.setWindow(std::move(window));
		}

		void Application::run(){
			window.showWindow();

			// Use the startup function that the user defined (if he had)
			startup();

			float delta;
			while (!window.shouldClose()) {
				delta = timer.getDelta();
				update(delta);
				render(delta);

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