#pragma once
#include "ztengine.h"
#include <vector>
#include <glm/gtc/noise.hpp>

#define CX 100
#define CZ 100
#define CY 20

typedef glm::tvec3<GLbyte> byte3;
using ngengine::render::Buffer;

class Chunk {

public:
	Chunk() {
	}

	~Chunk() {
	}

	void setProgramId(GLuint program) {
		attribute_coord = glGetAttribLocation(program, "coord");
		glEnableVertexAttribArray(attribute_coord);
	}
	/*
	void update() {
		int i = 0;

		byte4 vertex[CX * CY * CZ * 6 * 6];
		changed = false;

		for (int x = 0; x < CX; x++) {
			for (int z = 0; z < CZ; z++) {
				for (int y = 0; y < CY; y++) {
					for (int j = 0; j < 36; j++) {
						int indicy = cube_indices[j];
						int verticesIndicyIndex = indicy * 3;
						glm::vec3 vertecy = glm::vec3(
							cube_vertices[verticesIndicyIndex],
							cube_vertices[verticesIndicyIndex + 1],
							cube_vertices[verticesIndicyIndex + 2]);

						vertex[i++] = byte4(x*3 + vertecy.x,
							y*3 + vertecy.y,
							z*3 + vertecy.z, 0);
					}
				}
			}
		}

		elements = i;
		vbo.bind();
		glBufferData(GL_ARRAY_BUFFER, elements * sizeof *vertex, vertex, GL_STATIC_DRAW);
		vbo.unbind();
	}*/
	
	void update() {
		int i = 0;
		std::vector<byte3> vertex;
		changed = false;
		int indicy;
		int verticesIndicyIndex;
		float xFactor = 1.0f / (CX - 1);
		float zFactor = 1.0f / (CZ - 1);

		for (short x = 0; x < CX; x++) {
			for (short z = 0; z < CZ; z++) {
				for (short y = 0; y < CY; y++) {
					auto perlin = glm::perlin(glm::vec2(x * xFactor, z * zFactor));
					perlin = round(perlin * 100.0f);
					for (short j = 0; j < 36; j++) {
						indicy = cube_indices[j];
						verticesIndicyIndex = indicy * 3;
						glm::vec3 pos = glm::vec3(x + cube_vertices[verticesIndicyIndex],
												  perlin + y + cube_vertices[verticesIndicyIndex + 1],
												  z  + cube_vertices[verticesIndicyIndex + 2]);
						vertex.push_back(byte3(pos));
					}
				}
			}
		}

		elements = vertex.size();
		vbo.bind();
		glBufferData(GL_ARRAY_BUFFER, vertex.size() * 3, &vertex.front(), GL_STATIC_DRAW);
		vbo.unbind();
	}

	void render() {
		if (changed)
			update();

		// Render the VBO here
		if (!elements)
			return;

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

		vbo.bind(); 
		glVertexAttribPointer(attribute_coord, 3, GL_BYTE, GL_FALSE, 0, 0);
		glDrawArrays(GL_TRIANGLES, 0, elements);
		vbo.unbind();
	}

public:
	Buffer vbo{ GL_ARRAY_BUFFER };
	int elements;
	bool changed = true;
	GLint attribute_coord;

	const GLbyte cube_vertices[24] = {
		//front 
		-1, -1,  1,
		1, -1,  1,
		1,  1,  1,
		-1,  1,  1,
		//back
		-1, -1, -1,
		1, -1, -1,
		1,  1, -1,
		-1,  1, -1,
	};

	const GLbyte cube_indices[36] = {
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
};