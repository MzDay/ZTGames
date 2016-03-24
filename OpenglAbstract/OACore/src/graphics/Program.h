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
			GLuint getProgram() { return program; }
			inline void useProgram() { glUseProgram(program); }
			void addShader(std::initializer_list<Shader>);
		private:
			Program& operator=(const Program&) = delete;
			Program(const Program&) = delete;

			GLuint program;
		};
	}
}