#include "Game.h"

void Game::startup() {

	program.createProgram();
	
	Shader vertex{ GL_VERTEX_SHADER, "vertex.glsl" };
	Shader fragment{ GL_FRAGMENT_SHADER, "fragment.glsl" };

	program.addShader({ vertex, fragment });

	static const GLfloat positions[] = { -0.5f, -0.5f, 0.0f,
										  0.5f, -0.5f, 0.0f,
										  0.0f,  0.5f, 0.0f };

	glGenBuffers(1, &buf);
	glGenVertexArrays(1, &vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, buf);

	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), reinterpret_cast<GLvoid*>(0));

	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	program.useProgram();
}

void Game::update(double time) {

}

void Game::render(double time) {
	
	float r = static_cast<float>(std::sin(time));
	float g = static_cast<float>(std::cos(time));
	float b = static_cast<float>(std::sin(time));

	GLfloat black[] = { r, g, b, 0.0f };
	glClearBufferfv(GL_COLOR, 0, black);
	
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Game::userCallback() {

}

void Game::shutdown() {

}