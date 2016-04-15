#pragma once
#include "app\Application.h"

namespace ngengine {
	namespace render {
		class VertexArray
		{
		public:
			VertexArray();
			~VertexArray();
			
		public:
			VertexArray(const VertexArray&) = delete;
			VertexArray(VertexArray&&) = delete;
			VertexArray& operator = (const VertexArray&) = delete;
			VertexArray& operator = (VertexArray&&) = delete;

		public:
			void bind();
			void unbind();
			
			void setVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

		public:
			inline GLuint getHandle() const { return vaoHandle; };

		private:
			GLuint vaoHandle;
			bool bindToVAO;
		};
	}
}
