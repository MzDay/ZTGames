#pragma once

#include "ngengine.h"
#include "app\Application.h"
#include "Shader.h"

namespace ngengine {
	namespace graphics {

		class Program
		{
		public:
			Program() : program(glCreateProgram()) {};
			~Program() { glDeleteProgram(program); }

		public:
			GLuint getProgram() { return program; }
			inline void useProgram() { glUseProgram(program); }
			void addShader(Shader shader);
			void addShaders(std::initializer_list<Shader> shaderList);

		private:
			Program& operator=(const Program&) = delete;
			Program(const Program&) = delete;

		private:
			GLuint program;
		};
	}
}