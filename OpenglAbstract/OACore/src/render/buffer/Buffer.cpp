#include "ngengine.h"
#include "Buffer.h"

namespace ngengine {
	namespace render {
		Buffer::~Buffer()
		{
			glDeleteBuffers(1, &bufferHandle);
		}

		GLuint ngengine::render::Buffer::getHandle() const
		{
			return bufferHandle;
		}

		GLenum Buffer::getTarget() const
		{
			return bufferTarget;
		}

		GLenum Buffer::getUsage() const
		{
			return bufferUsage;
		}

		void Buffer::setTarget(GLenum newBufferTarget)
		{
			bufferTarget = newBufferTarget;
		}

		void Buffer::setData(const GLvoid * data, GLsizeiptr sizeInBytes, GLenum usage)
		{
			if(bufferTarget == 0)
			{
				// TODO: Throw error because the user didn't declare any target
				throw std::exception("Didn't declare target");
			}

			bufferUsage = usage;

			glBufferData(bufferTarget, sizeInBytes, data, usage);
		}

		void Buffer::bind()
		{
			 glBindBuffer(bufferTarget, bufferHandle);
		}

		void Buffer::unbind()
		{
			 glBindBuffer(bufferTarget, 0);
		}
	}
}
