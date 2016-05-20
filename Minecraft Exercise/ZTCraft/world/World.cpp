#include "World.h"

const GLfloat World::cube_vertices[] = {
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

const GLuint World::cube_elements[] = {
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

void World::render(float delta) {
	 vao.bind();
	 chunks[glm::ivec3(0.0, 0.0, 0.0)].render();
	 vao.unbind();
}

void World::update(float delta) {
}