#include "Game.h"

void Game::startup() {
	Shader vertex = { GL_VERTEX_SHADER, "vertex.glsl" };
	Shader fragment = { GL_FRAGMENT_SHADER, "fragment.glsl" };
	program.addShader({ vertex, fragment });

	glEnable(GL_DEPTH_TEST);

	program.useProgram();

	// Bind the program with the blocks
	Block::setProgramId(program.getProgram());

	projection = glm::perspective(glm::radians(45.0f), window.getWindowRatio(), 0.1f, 100.0f);
	GLuint projectionLoc = program.getUniformLocation("projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	player.physics.position = glm::vec3(20.0f, 10.0f, 45.0f);
	player.SetInputManager(inputManager);
}

void Game::render(double delta) {
	// We only have one program so this is fine for now

	static const GLfloat color[] = { 0.6f, 0.7f, 0.5f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, color);
	glClear(GL_DEPTH_BUFFER_BIT);

	world.render(delta);
	player.Update(delta);
}

void Game::update(double delta) {
	world.update(delta);

	glm::mat4 lookat = player.camera.getLookAt();
	GLuint lookatLoc = program.getUniformLocation("lookat");
	glUniformMatrix4fv(lookatLoc, 1, GL_FALSE, glm::value_ptr(lookat));
}

void Game::shutdown() {

}

