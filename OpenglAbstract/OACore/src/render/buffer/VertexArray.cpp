#include "ngengine.h"
#include "VertexArray.h"

namespace ngengine {
	namespace render {

		VertexArray::VertexArray() : bindToVAO(false)
		{
			glGenVertexArrays(1, &vaoHandler);
		}

		VertexArray::~VertexArray()
		{
		}

		void VertexArray::bind(){
			if(!bindToVAO)
			{
				bindToVAO = true;
				glBindVertexArray(vaoHandler);
			}
		}

		void VertexArray::unbind(){
			if(bindToVAO)
			{
				bindToVAO = false;
				glBindVertexArray(0);
			}
		}

		void VertexArray::load(std::function<void()> lamb)
		{
			bind();
			// Here we let the user run his own function
			// so he can decide what to do with the VAO
			lamb();
			unbind();
		}

		void VertexArray::setVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer){
			if(bindToVAO)
			{
				glVertexAttribPointer(index, size, type, normalized, stride, pointer);
				glEnableVertexAttribArray(index);
			}
			else
			{
				// TODO: Log/Throw a warning to tell the user he didn't bind the VAO
				// and this action will not work
			}
		}
	}
}
