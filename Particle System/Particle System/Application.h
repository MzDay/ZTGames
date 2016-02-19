#pragma once

#include <iostream>
#include <GL/gl3w.h>

#define GLFW_NO_GLU 1
#define GLFW_INCLUDE_GLCOREARB 1

#include <GLFW/glfw3.h>

#pragma comment(lib, "glfw3_d.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "opengl32.lib")

class Application {
public:
	virtual void startup() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void userCallback() = 0;

	void runApp() {
		_startup();
	}

private:

	void handleApp() {
		while (!glfwWindowShouldClose(window))
		{
			update();
			render();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	static void error_callback(int error, const char* description)
	{
		//fputs(description, stderr);
		std::cerr << description;
	}

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}

	void _startup() {
		glfwSetErrorCallback(error_callback);
		if (!glfwInit())
			exit(EXIT_FAILURE);

		window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);
		glfwSetKeyCallback(window, key_callback);
		
		handleApp();

		glfwDestroyWindow(window);
		glfwTerminate();

		startup();
	}


	GLFWwindow* window;
};