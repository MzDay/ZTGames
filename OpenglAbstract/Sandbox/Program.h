#ifndef PROGRAM_H
#define PROGRAM_H

#include "app\Application.h"
#include "Shader.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

class Program
{
public:
	Program() {};
	~Program() { glDeleteProgram(program); }
	inline void createProgram() { program = glCreateProgram(); }
	GLuint getProgram() { return program; }
	void useProgram() { glUseProgram(program); }
	void addShader(std::initializer_list<Shader>);
private:
	Program& operator=(const Program&) = delete;
	Program(const Program&) = delete;

	GLuint program;
};

#endif