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
			void load(std::function<void()> lamb);
			
			void setVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

		public:
			inline GLuint getHandler() const { return vaoHandler; };

		private:
			GLuint vaoHandler;
			bool bindToVAO;
		};
	}
}
