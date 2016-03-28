#include "ngengine.h"
#include "Buffer.h"

namespace ngengine {
	namespace render {
		Buffer::~Buffer()
		{
		}

		GLuint ngengine::render::Buffer::getHandler() const
		{
			return bufferHandler;
		}

		GLenum Buffer::getTarget() const
		{
			return bufferTarget;
		}

		GLenum Buffer::getUsage() const
		{
			return bufferUsage;
		}

		inline void Buffer::setData(const GLvoid * data, GLenum usage, GLsizeiptr sizeInBytes)
		{
			glBindBuffer(bufferTarget, bufferHandler);
			glBufferData(bufferTarget, sizeInBytes, data, usage);
			glBindBuffer(bufferTarget, 0);
		}
	}
}