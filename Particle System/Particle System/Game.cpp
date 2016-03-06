#include "Game.h"

#define MANY_CUBES

void Game::startup()
{

	userWindowResizeCallback(640, 480);

	program.createProgram();

	Shader vertex{ GL_VERTEX_SHADER, "vertex.glsl" };
	Shader fragment{ GL_FRAGMENT_SHADER, "fragment.glsl" };

	program.addShader({ vertex, fragment });

	mv_location = glGetUniformLocation(program.getProgram(), "mv_matrix");
	proj_location = glGetUniformLocation(program.getProgram(), "proj_matrix");

	static const GLfloat positions[] =
	{
		-0.25f,  0.25f, -0.25f,
		-0.25f, -0.25f, -0.25f,
		0.25f, -0.25f, -0.25f,

		0.25f, -0.25f, -0.25f,
		0.25f,  0.25f, -0.25f,
		-0.25f,  0.25f, -0.25f,

		0.25f, -0.25f, -0.25f,
		0.25f, -0.25f,  0.25f,
		0.25f,  0.25f, -0.25f,

		0.25f, -0.25f,  0.25f,
		0.25f,  0.25f,  0.25f,
		0.25f,  0.25f, -0.25f,

		0.25f, -0.25f,  0.25f,
		-0.25f, -0.25f,  0.25f,
		0.25f,  0.25f,  0.25f,

		-0.25f, -0.25f,  0.25f,
		-0.25f,  0.25f,  0.25f,
		0.25f,  0.25f,  0.25f,

		-0.25f, -0.25f,  0.25f,
		-0.25f, -0.25f, -0.25f,
		-0.25f,  0.25f,  0.25f,

		-0.25f, -0.25f, -0.25f,
		-0.25f,  0.25f, -0.25f,
		-0.25f,  0.25f,  0.25f,

		-0.25f, -0.25f,  0.25f,
		0.25f, -0.25f,  0.25f,
		0.25f, -0.25f, -0.25f,

		0.25f, -0.25f, -0.25f,
		-0.25f, -0.25f, -0.25f,
		-0.25f, -0.25f,  0.25f,

		-0.25f,  0.25f, -0.25f,
		0.25f,  0.25f, -0.25f,
		0.25f,  0.25f,  0.25f,

		0.25f,  0.25f,  0.25f,
		-0.25f,  0.25f,  0.25f,
		-0.25f,  0.25f, -0.25f
	};

	glGenBuffers(1, &buf);
	glGenVertexArrays(1, &vao);

	glBindBuffer(GL_ARRAY_BUFFER, buf);

	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(0);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);

	program.useProgram();
}

void Game::update(double currentTime) {

}

void Game::render(double currentTime)
{
	static const GLfloat green[] = { 0.0f, 0.25f, 0.0f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, green);
	glClearBufferfi(GL_DEPTH_STENCIL, 0, 1.0f, 0);

	glUniformMatrix4fv(proj_location, 1, GL_FALSE, glm::value_ptr(proj_matrix));

#ifdef MANY_CUBES

	for (int i = 0; i < 24; ++i) {
		float time = (float)(i)+(float)(currentTime)* 0.3f;

		int isNegativeOffset = (i % 2 == 0) ? 1 : -1;
		float xOffset = (i % 6) * 3;
		float yOffset = (i / 6) * 3;

		glm::mat4 location_matrix = glm::translate(glm::vec3(0.0f + xOffset, 0.0f + yOffset, -5.0f * (i % 2)));
		glm::mat4 move_animaiton_matrix = glm::translate(glm::vec3(
			sinf(2.1f * time),
			cosf(2.7f * time),
			sinf(1.3f * time) * cosf(1.5f * time)));

		glm::mat4 rotate_x_matrix = glm::rotate(glm::radians((float)currentTime * 45.0f + i), glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rotate_y_matrix = glm::rotate(glm::radians((float)currentTime * 45.0f + i), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 rotate_z_matrix = glm::rotate(glm::radians((float)currentTime * 45.0f + i), glm::vec3(0.0f, 0.0f, 1.0f));

		glm::mat4 mv_matrix = camera_matrix * location_matrix * move_animaiton_matrix * rotate_x_matrix * rotate_y_matrix * rotate_z_matrix;

		glUniformMatrix4fv(mv_location, 1, GL_FALSE, glm::value_ptr(mv_matrix));

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

#else

	float time = (float)currentTime *  0.7f;

	glm::mat4 location_matrix = glm::translate(glm::vec3(0.0f, 0.0f, -4.0f));
	glm::mat4 move_animation_matrix = glm::translate((glm::vec3(
		sinf(2.1f * time) * 0.5f,
		cosf(1.7f * time) * 0.5f,
		sinf(1.3f * time) * cosf(1.5f * time) * 2.0f)));

	glm::mat4 rotate_y_matrix = glm::rotate(glm::radians((float)currentTime * 81.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotate_z_matrix = glm::rotate(glm::radians((float)currentTime * 81.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 rotate_x_matrix = glm::rotate(glm::radians((float)currentTime * 45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 mv_matrix = camera_matrix * move_animation_matrix * location_matrix;

	glUniformMatrix4fv(mv_location, 1, GL_FALSE, glm::value_ptr(mv_matrix));

	glDrawArrays(GL_TRIANGLES, 0, 36);

#endif
}

void Game::userKeyCallback(int key, int action) {
	if (key == GLFW_KEY_W) {
		camera_matrix *= glm::translate(glm::vec3(0.0f, -0.5f, 0.0f));
	}
	if (key == GLFW_KEY_S) {
		camera_matrix *= glm::translate(glm::vec3(0.0f, 0.5f, 0.0f));
	}

	if (key == GLFW_KEY_D) {
		camera_matrix *= glm::translate(glm::vec3(-0.5f, 0.0f, 0.0f));
	}
	if (key == GLFW_KEY_A) {
		camera_matrix *= glm::translate(glm::vec3(0.5f, 0.0f, 0.0f));
	}

	if (key == GLFW_KEY_EQUAL) {
		camera_matrix *= glm::translate(glm::vec3(0.0f, 0.0f, -0.5));
	}
	if (key == GLFW_KEY_MINUS) {
		camera_matrix *= glm::translate(glm::vec3(0.0f, 0.0f, 0.5));
	}

	if (key == GLFW_KEY_UP) {
		camera_matrix *= glm::rotate(float(glm::radians(-1.0f)), glm::vec3(1.0f, 0.0f, 0.0f));
	}
	if (key == GLFW_KEY_DOWN) {
		camera_matrix *= glm::rotate(float(glm::radians(1.0f)), glm::vec3(1.0f, 0.0f, 0.0f));
	}
	if (key == GLFW_KEY_LEFT) {
		camera_matrix *= glm::rotate(float(glm::radians(-1.0f)), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	if (key == GLFW_KEY_RIGHT) {
		camera_matrix *= glm::rotate(float(glm::radians(1.0f)), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	if (key == GLFW_KEY_R) {
		camera_matrix = glm::translate(glm::vec3(0.0f, 0.0f, 0.0f));
	}
}

void Game::shutdown() {

}

void Game::userWindowResizeCallback(int w, int h)
{
	aspect = (float)w / (float)h;
	proj_matrix = glm::perspective(45.0f, aspect, 0.1f, 1000.0f);

	glViewport(0, 0, w, h);
}
