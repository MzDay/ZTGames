#include "ngengine.h"
#include "Application.h"

namespace ngengine {
	namespace app{
		Application::Application(const string& title, const Size2D size) : 
			m_Title(title), m_Size(size), m_Window(title, size){
			if (!glfwInit()) {
				//TODO: Log error
				std::cerr << "GLFW failed to init" << std::endl;
			}

			m_Window.createWindow();
		}

		void Application::run(){
			// Make the window context current
			m_Window.makeContext();

			if (glewInit() != GLEW_OK) {
				std::cerr << "GLEW failed to init" << std::endl;
			}

			startup();

			while (!m_Window.shouldClose()) {
				update(glfwGetTime());
				render(glfwGetTime());

				m_Window.updateWindow();
			}
		}

		void Application::setTitle(const string& title) {
			m_Window.setTitle(title);
		}

		Application::~Application() {
			// TODO: Delete every allocated memory
			shutdown();
			glfwTerminate();
		}
	}
}