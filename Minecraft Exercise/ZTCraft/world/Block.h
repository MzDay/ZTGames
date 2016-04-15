#pragma once
#include "ztengine.h"
#include "glm/gtc/type_ptr.hpp"

using ngengine::render::VertexArray;
using ngengine::render::Buffer;

class Block {

public:
	 // TODO: Check why this is called twice when we make a test block in the Game.h with member initialization
	 Block(float x, float y, float z) : xPos(x), yPos(y), zPos(z) {
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
	 void render(double delta);
	 void update(double delta);

public:
	 // We do this so we wont have to get the program everytime
	 static void Block::setProgramId(GLuint program) {
		  modelLocation = glGetUniformLocation(program, "model");
	 }

private:
	 float xPos;
	 float yPos;
	 float zPos;
	 VertexArray vao;
	 Buffer vbo{ GL_ARRAY_BUFFER };
	 Buffer ebo{ GL_ELEMENT_ARRAY_BUFFER };
	 glm::mat4 model;

private:
	 static GLuint Block::modelLocation;

private:
	 static const GLfloat  cube_vertices[24];
	 static const GLuint cube_indices[14];
};