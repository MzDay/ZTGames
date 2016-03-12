#ifndef SHADER_H
#define SHADER_H

#include "app\Application.h"

struct Shader {
	const GLenum shaderType;
	const char* fileLocation;
};

#endif