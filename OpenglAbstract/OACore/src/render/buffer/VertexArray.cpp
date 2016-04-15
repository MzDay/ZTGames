#include "ngengine.h"
#include "VertexArray.h"

namespace ngengine {
	namespace render {

		VertexArray::VertexArray() : bindToVAO(false)
		{
			glGenVertexArrays(1, &vaoHandle);
		}

		VertexArray::~VertexArray()
		{
			 glDeleteVertexArrays(1, &vaoHandle);
		}

		void VertexArray::bind(){
			if(!bindToVAO)
			{
				bindToVAO = true;
				glBindVertexArray(vaoHandle);
			}
		}

		void VertexArray::unbind(){
			if(bindToVAO)
			{
				bindToVAO = false;
				glBindVertexArray(0);
			}
		}

		void VertexArray::setVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer){
			if(!bindToVAO)
				 throw std::exception("You didn't bind the vao!");

			glVertexAttribPointer(index, size, type, normalized, stride, pointer);
			glEnableVertexAttribArray(index);
		}
	}
}
