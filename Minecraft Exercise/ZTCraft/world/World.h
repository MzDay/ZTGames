#pragma once

#include <ztengine.h>
#include <unordered_map>
#include "SeedBasedRandom.h"
#include <glm\glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using ngengine::render::VertexArray;
using ngengine::render::Buffer;

namespace std {
	 template<>
	 struct hash<glm::ivec3> {
		  std::size_t operator()(const glm::ivec3& k) const{
			   using std::hash;
			   return ((hash<int>()(k.x)
						 ^ (hash<int>()(k.y) << 1)) >> 1)
						 ^ (hash<int>()(k.z) << 1);
		  }
	 };
}

struct Block {
	 int x;
	 int y;
	 int z;
	 int type; // For now..
};

class Chunk {
public:
	 Chunk() {}
	 ~Chunk() {}
	 Chunk(const Chunk& o) : blocks(o.blocks) { }
	 Chunk(Chunk&& o) noexcept : blocks(std::move(o.blocks)) {}
	 Chunk& operator=(const Chunk& o) { blocks = o.blocks; return *this; }
	 Chunk& operator=(Chunk&& o) { blocks = std::move(o.blocks); return *this; }
	 
public:
	 void loadData(std::unordered_map<glm::ivec3, Block> data) {
		  blocks = data; // Hopefully this will implement move semantics
	 }

	 void render() {
		  // BAD BAD BADDD
		  GLint id;
		  glGetIntegerv(GL_CURRENT_PROGRAM, &id);
		  GLuint model_pos = glGetUniformLocation(id, "model");
		  for (auto kv : blocks) {
			   glm::mat4 model;
			   model = glm::translate(model, glm::vec3(kv.second.x, kv.second.y, kv.second.z));
			   glUniformMatrix4fv(model_pos, 1, GL_FALSE, glm::value_ptr(model));
			   glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
		  }
	 }

private:
	 std::unordered_map<glm::ivec3, Block> blocks;
};

class World {
public:
	World() : seed(123) {
		 vao.bind();
		 ebo.bind(); 
		 vbo.bind();
		 ebo.setData(cube_elements, sizeof(cube_elements), GL_STATIC_DRAW);
		 vbo.setData(cube_vertices, sizeof(cube_vertices), GL_STATIC_DRAW);
		 vao.setVertexAttrib(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		 vao.unbind();
		 ebo.unbind();
		 vbo.unbind();

		 Chunk test;
		 std::unordered_map<glm::ivec3, Block> data;

		 for (int x = 0; x < 100; ++x) {
			  for (int y = 0; y < 100; ++y) {
				   for (int z = 0; z < 5; ++z) {
						data[glm::ivec3(x, y, z)] = Block{ x,y,z,0 };
				   }
			  }
		 }
		 test.loadData(data);
		 chunks[glm::ivec3(0.0, 0.0, 0.0)] = std::move(test);
	}

public:
	void render(float delta);
	void update(float delta);

private:
	SeedBasedRandom<0, 20> seed;
	std::unordered_map<glm::ivec3, Chunk> chunks; // CHECK IF WE DO NOT GET MEMORY LEAKS + IF THE DATA IS OK!!
	
	Buffer vbo{ GL_ARRAY_BUFFER };
	Buffer ebo{ GL_ELEMENT_ARRAY_BUFFER };
	VertexArray vao;

	static const GLfloat cube_vertices[24];
	static const GLuint cube_elements[36];
};
