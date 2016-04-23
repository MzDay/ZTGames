#pragma once
#include "ztengine.h"
#include "glm/gtc/type_ptr.hpp"
#include <vector>

using ngengine::render::VertexArray;
using ngengine::render::Buffer;
using ngengine::utils::Pos3D;

struct Block {
	glm::mat4 model;

	Block(Pos3D position) : 
		model(glm::translate(glm::mat4(), glm::vec3(position.x, position.y, position.z))) {}
};

class BlockRenderer {

public:
	// TODO: Check why this is called twice when we make a test block in the Game.h with member initialization
	BlockRenderer() {
		// * THIS ORDER IS IMPORTANT
		// [NOTE] Maybe give vao the buffers and let him handle all this?
		// First we need to bind the VAO
		vao.bind();

		// Than we need to bind the wanted buffers
		vbo.bind();
		ebo.bind();

		// Set the data andn vertex attribute in this order (buffers data not important)
		vbo.setData(cube_vertices, sizeof(cube_vertices), GL_STATIC_DRAW);
		ebo.setData(cube_indices, sizeof(cube_indices), GL_STATIC_DRAW);
		vao.setVertexAttrib(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);

		// unbind the VAO *IMPORTANT*
		vao.unbind();

		// unbind the wanted buffers
		vbo.unbind();
		ebo.unbind();
	}

public:
	void render(float delta, Block blocks);
	void update(float delta, Block block);

public:
	// We do this so we wont have to get the program everytime
	static void BlockRenderer::setProgramId(GLuint program) {
		BlockRenderer::modelLocation = glGetUniformLocation(program, "model");
	}

private:
	VertexArray vao;
	Buffer vbo{ GL_ARRAY_BUFFER };
	Buffer ebo{ GL_ELEMENT_ARRAY_BUFFER };

private:
	static GLuint BlockRenderer::modelLocation;

private:
	static const GLfloat  cube_vertices[24];
	static const GLuint cube_indices[36];
};