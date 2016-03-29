#pragma once

#include "ztengine.h"
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

private:
	Program program;

	VertexArray vao;
	Buffer vbo;
	Buffer ebo;

	Camera camera;

	Pyramid pyramid;

	//InputHandler* input;
};