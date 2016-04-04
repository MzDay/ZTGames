#pragma once

<<<<<<< HEAD
#include "app\Application.h"
=======
#include "ztengine.h"
>>>>>>> Dev
#include "graphics\Program.h"
#include "glm\glm.hpp"
#include "glm\gtx\transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include <array>
#include "Pyramid.h"

using ngengine::app::Application;
using ngengine::graphics::Program;
using ngengine::graphics::Shader;
using ngengine::render::Buffer;
using ngengine::render::VertexArray;
using ngengine::scene::Camera;

class Game : public Application {
public:
	Game(const std::string& title) : Application(title),
		vbo(GL_ARRAY_BUFFER),
		ebo(GL_ELEMENT_ARRAY_BUFFER) {}

public:
	void render(double) override;
	void update(double) override;
	void startup() override;
	void shutdown() override;
<<<<<<< HEAD
	void keyCallback(int, int) override;
	void mouseCallback(double, double) override;
=======
>>>>>>> Dev

private:
	Program program;

<<<<<<< HEAD
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	GLfloat cameraYaw;
	GLfloat cameraPitch;
	GLboolean firstMouse;

	GLdouble mouseLastX;
	GLdouble mouseLastY;

	Pyramid pyramid;

	std::array<bool, 1024> keysState;
=======
	VertexArray vao;
	Buffer vbo;
	Buffer ebo;

	Camera camera;

	Pyramid pyramid;
>>>>>>> Dev
};