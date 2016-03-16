#pragma once

#include "ngengine.h"
#include "app\Application.h"

namespace ngengine {
	namespace graphics {
		struct Shader {
			const GLenum shaderType;
			const char* fileLocation;
		};
	}
}