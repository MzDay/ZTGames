#include "BlockRenderer.h"

GLuint BlockRenderer::modelLocation;

void BlockRenderer::render(float delta, Block block)
{
	 vao.bind();
		  glDrawElements(GL_TRIANGLE_STRIP, 36, GL_UNSIGNED_INT, 0);
	 vao.unbind();
}

void BlockRenderer::update(float delta, Block block) {
	 glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(block.model));
}

const GLfloat BlockRenderer::cube_vertices[] = {
	 -0.5, -0.5,  0.5,
	 0.5, -0.5,  0.5,
	 -0.5,  0.5,  0.5,
	 0.5,  0.5,  0.5,
	 -0.5, -0.5, -0.5,
	 0.5, -0.5, -0.5,
	 -0.5,  0.5, -0.5,
	 0.5,  0.5, -0.5,
};

const GLuint BlockRenderer::cube_indices[] = {
	 0, 1, 2,
	 3, 7, 1,
	 5, 4, 7,
	 6, 2, 4,
	 0, 1
};