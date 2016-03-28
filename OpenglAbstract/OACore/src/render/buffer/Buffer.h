#pragma once

#include "app\Application.h"

namespace ngengine {
	namespace render {
		class Buffer {
		public:
			Buffer() = delete;
			Buffer(const Buffer&) = delete;
			Buffer(Buffer&&) = delete;
			Buffer& operator = (const Buffer&) = delete;
			Buffer& operator = (Buffer&&) = delete;

			Buffer(GLenum newBufferTarget) : bufferTarget(newBufferTarget) {}
			~Buffer();

		public:
			GLuint getHandler() const;
			GLenum getTarget() const;
			GLenum getUsage() const;

			void setData(const GLvoid* data, GLenum usage, GLsizeiptr sizeInBytes);

		private:
			GLenum bufferTarget;
			GLenum bufferUsage;
			GLuint bufferHandler;
		};
	}
}