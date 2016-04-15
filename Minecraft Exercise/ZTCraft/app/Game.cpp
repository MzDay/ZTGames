#include "Game.h"

void Game::startup() {
	 Shader vertex = { GL_VERTEX_SHADER, "vertex.glsl" };
	 Shader fragment = { GL_FRAGMENT_SHADER, "fragment.glsl" };
	 program.addShader({ vertex, fragment });

	 glEnable(GL_DEPTH_TEST);

	 program.useProgram();

	 // Bind the program with the blocks
	 Block::setProgramId(program.getProgram());

	 projection = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.1f, 100.0f);
	 GLuint projectionLoc = program.getUniformLocation("projection");
	 glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	 camera.setPosition(glm::vec3(20.0f, 10.0f, 45.0f));
}

void Game::render(double delta) {	 
	 // We only have one program so this is fine for now
	 
	 static const GLfloat color[] = { 0.6f, 0.7f, 0.5f, 1.0f };
	 glClearBufferfv(GL_COLOR, 0, color);
	 glClear(GL_DEPTH_BUFFER_BIT);

	 world.render(delta);
}

void Game::update(double delta) {
	 camera.update();
	 world.update(delta);

	 lookat = camera.getLookAt();
	 GLuint lookatLoc = program.getUniformLocation("lookat");
	 glUniformMatrix4fv(lookatLoc, 1, GL_FALSE, glm::value_ptr(lookat));
}

void Game::shutdown() {

}