#include "Game.h"

void Game::startup() {

	program.createProgram();

	Shader vertex{ GL_VERTEX_SHADER, "vertex.glsl" };
	Shader fragment{ GL_FRAGMENT_SHADER, "fragment.glsl" };

	program.addShader({ vertex, fragment });

	static const GLfloat positions[] =
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f,
		-0.5f, 0.25f, 0.0f,
		0.5f, 0.25f, 0.0f,
		0.0f,  -0.75f, 0.0f,
	};

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

void Game::update(double currentTime) {

}

void Game::render(double currentTime) {
	static const GLfloat green[] = { 0.0f, 0.25f, 0.0f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, green);
	glClearBufferfi(GL_DEPTH_STENCIL, 0, 1.0f, 0);

	glUniformMatrix4fv(proj_location, 1, GL_FALSE, proj_matrix);

#ifdef MANY_CUBES
	
	for (int i = 0; i < 24; ++i) {
		float time = staic_cast<float>(i) + staic_cast<float>(currentTime) * 0.7f;

		glm::mat4 location_matrix = glm::translate(0.0f, 0.0f, -10.0f);
		glm::mat4 move_animaiton_matrix = glm::translate(
			sinf(2.1f * time) * i,
			cosf(1.7f * time) * i,
			sinf(1.3f * time) * cosf(1.5f * time * i);
	}

#else

#endif
}

void Game::userCallback() {

}

void Game::shutdown() {

}