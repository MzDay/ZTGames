#include <iostream>
#include "app\Application.h"
#include "utils\Size.h"
#include <vector>
#include "Program.h"

using ngengine::utils::Size2D;

class Game : public ngengine::app::Application
{
	NG_ENGINE_BASE;

	void startup() {
		program.createProgram();
		Shader vertex{ GL_VERTEX_SHADER, "vertex.glsl" };
		Shader fragment{ GL_FRAGMENT_SHADER, "fragment.glsl" };
		program.addShader({vertex, fragment});

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
	}

	void update(double) {
		
	}

	void render(double time) {
		static const GLfloat backcolor[] = { 1.0f , 1.0f, 1.0f, 1.0f };
		const GLfloat color[] = { cos(time) + 0.5f, sin(time), cos(time), 1.0f };
		//const GLfloat position[] = { cos(time) , sin(time), cos(time), 1.0f };
		glClearBufferfv(GL_COLOR, 0, backcolor);
		
		std::tuple<float, float> mousePos = getNormalizedMousePos(getWindowSize());
		const GLfloat position[] = { std::get<0>(mousePos), std::get<1>(mousePos)};

		GLuint pos = glGetUniformLocation(program.getProgram(), "pos");
		GLuint colorIndex = glGetUniformLocation(program.getProgram(), "color");

		glUniform4fv(colorIndex, 1, color);
		glUniform2fv(pos, 1, position);

		glUseProgram(program.getProgram());
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	GLuint vao;
	Program program;
};

int main() {
	Game game("Naor");
	game.run();

	return 0;
}