#pragma once
#include "ztengine.h"
#include <vector>
#include <glm/gtc/noise.hpp>

#define CX 600
#define CZ 600
#define CY 3

typedef glm::tvec3<float> float3;
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

	void update() {
		int i = 0;
		std::vector<float3> vertex;
		changed = false;
		int indicy;
		int verticesIndicyIndex;
		float xFactor = 1.0f / (CX - 1);
		float zFactor = 1.0f / (CZ - 1);

		for (float x = 0; x < CX; x++) {
			for (float z = 0; z < CZ; z++) {
				for (float y = 0; y < CY; y++) {
					auto perlin = glm::perlin(glm::vec2(x * xFactor, z * zFactor));
					perlin = round(perlin * 1000.0f);
					for (short j = 0; j < 36; j++) {
						indicy = cube_indices[j];
						verticesIndicyIndex = indicy * 3;
						glm::vec3 pos = glm::vec3(x * 2 + cube_vertices[verticesIndicyIndex],
							perlin + y * 2 + cube_vertices[verticesIndicyIndex + 1],
							z * 2 + cube_vertices[verticesIndicyIndex + 2]);
						vertex.push_back(float3(pos));
					}
				}
			}
		}

		elements = vertex.size();
		vbo.bind();
		glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(float3), &vertex.front(), GL_STATIC_DRAW);
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
		glVertexAttribPointer(attribute_coord, 3, GL_FLOAT, GL_FALSE, 0, 0);
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