#ifndef PROGRAM_H
#define PROGRAM_H

#include <GL/gl3w.h>
#include "Shader.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class Program
{
public:
	Program() {};
	~Program() { glDeleteProgram(program); }
	inline void createProgram() { program = glCreateProgram(); }
	GLuint getProgram() { return program; }
	void useProgram() { glUseProgram(program); }
	void addShader(Shader);
private:
	Program& operator=(const Program&) = delete;
	Program(const Program&) = delete;

	GLuint program;
};

#endif