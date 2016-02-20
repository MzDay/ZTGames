#pragma once

#include <iostream>
#include <GL/gl3w.h>

#define GLFW_NO_GLU 1
#define GLFW_INCLUDE_GLCOREARB 1

#include <GLFW/glfw3.h>
#include "Logger.h"

#pragma comment(lib, "glfw3_d.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "opengl32.lib")

class Application {
public:
	virtual void startup() = 0;
	virtual void shutdown() = 0;
	virtual void render(double) = 0;
	virtual void update(double) = 0;
	virtual void userCallback() = 0;

	void runApp() {
		_startup();
	}

protected:
	Logger logger;
private:
	
	void _update(double time) {
		update(time);
	}

	void _render(double time) {
		render(time);
	}


	void handleApp() {
		while (!glfwWindowShouldClose(window))
		{
			_update(glfwGetTime());
			_render(glfwGetTime());
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

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);
		glfwSetKeyCallback(window, key_callback);
		
		gl3wInit();

		handleApp();

		glfwDestroyWindow(window);
		glfwTerminate();

		startup();
	}


	GLFWwindow* window;
};