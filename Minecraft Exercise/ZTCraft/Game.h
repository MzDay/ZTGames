#pragma once
#include "app\Application.h"
#include "graphics\Program.h"
#include "glm\glm.hpp"
#include "glm\gtx\transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include <array>

using ngengine::app::Application;
using ngengine::graphics::Program;
using ngengine::graphics::Shader;

class Game : public Application {
	using Application::Application;
public:
	void render(double) override;
	void update(double) override;
	void startup() override;
	void shutdown() override;
	void keyCallback(int, int) override;

private:
	Program program;
	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	std::array<bool, 1024> keys;
};