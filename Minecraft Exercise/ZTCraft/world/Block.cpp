#include "Block.h"

GLuint Block::modelLocation;

void Block::render(double delta)
{
	 vao.bind();	
		  glDrawElements(GL_TRIANGLE_STRIP, 36, GL_UNSIGNED_INT, 0);
	 vao.unbind();
}

void Block::update(double delta) {
	 model = glm::mat4();
	 model = glm::translate(model, glm::vec3(xPos, yPos, zPos));
	 glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
}

const GLfloat Block::cube_vertices[] = {
	 -0.5, -0.5,  0.5,
	 0.5, -0.5,  0.5,
	 -0.5,  0.5,  0.5,
	 0.5,  0.5,  0.5,
	 -0.5, -0.5, -0.5,
	 0.5, -0.5, -0.5,
	 -0.5,  0.5, -0.5,
	 0.5,  0.5, -0.5,
};

const GLuint Block::cube_indices[] = {
	 0, 1, 2,
	 3, 7, 1,
	 5, 4, 7,
	 6, 2, 4,
	 0, 1
};