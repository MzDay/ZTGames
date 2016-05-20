#include "BlockRenderer.h"

GLuint BlockRenderer::modelLocation;

void BlockRenderer::render(float delta, Block block)
{
	 vao.bind();
		  glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	 vao.unbind();
}

void BlockRenderer::update(float delta, Block block) {
	 glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(block.model));
}

const GLfloat BlockRenderer::cube_vertices[] = {
	//front 
	-0.5, -0.5,  0.5,
	 0.5, -0.5,  0.5,
	 0.5,  0.5,  0.5,
	 -0.5,  0.5,  0.5,
	//back
	 -0.5, -0.5, -0.5,
	 0.5, -0.5, -0.5,
	 0.5,  0.5, -0.5,
	 -0.5,  0.5, -0.5,
};

const GLuint BlockRenderer::cube_indices[] = {
	// front
	0, 1, 2,
	2, 3, 0,
	// top
	1, 5, 6,
	6, 2, 1,
	// back
	7, 6, 5,
	5, 4, 7,
	// bottom
	4, 0, 3,
	3, 7, 4,
	// left
	4, 5, 1,
	1, 0, 4,
	// right
	3, 2, 6,
	6, 7, 3,
};