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

		Size2D Application::getWindowSize()
		{
			return m_Window.getSize();
		}

		void Application::setTitle(const string& title) {
			m_Window.setTitle(title);
		}

		std::tuple<double, double> Application::getMousePos() {
			return m_Window.getMousePos();
		}

		std::tuple<double, double> Application::getNormalizedMousePos(Size2D windowSize)
		{
			double normalizedX, normalizedY;
			std::tuple<double, double> mousePos = m_Window.getMousePos();
			
			normalizedX = -1.0 + 2.0 * std::get<0>(mousePos) / windowSize.width;
			normalizedY = -(-1.0 + 2.0 * std::get<1>(mousePos) / windowSize.height);
			
			return std::make_tuple(normalizedX, normalizedY);
		}

		Application::~Application() {
			// TODO: Delete every allocated memory
			shutdown();
			glfwTerminate();
		}
	}
}