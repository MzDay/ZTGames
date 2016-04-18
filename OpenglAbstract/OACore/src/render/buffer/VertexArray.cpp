#include "ngengine.h"
#include "VertexArray.h"

namespace ngengine {
	namespace render {

		VertexArray::VertexArray() : boundToVAO(false)
		{
			glGenVertexArrays(1, &vaoHandle);
		}

		VertexArray::~VertexArray()
		{
			 glDeleteVertexArrays(1, &vaoHandle);
		}

		void VertexArray::bind(){
			if(!boundToVAO)
			{
				boundToVAO = true;
				glBindVertexArray(vaoHandle);
			}
		}

		void VertexArray::unbind(){
			if(boundToVAO)
			{
				boundToVAO = false;
				glBindVertexArray(0);
			}
		}

		void VertexArray::setVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer){
			if(!boundToVAO)
				 throw std::exception("You didn't bind the vao!");

			glVertexAttribPointer(index, size, type, normalized, stride, pointer);
			glEnableVertexAttribArray(index);
		}
	}
}
