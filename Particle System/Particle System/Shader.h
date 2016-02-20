#ifndef SHADER_H
#define SHADER_H

#include <GL\gl3w.h>

struct Shader {
	const GLenum shaderType;
	const char* fileLocation;
};

#endif