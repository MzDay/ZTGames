#include "Game.h"

void Game::startup() {
	const GLfloat positions[] = {
		-0.5, -0.5,  0.5,
		0.5, -0.5,  0.5,
		-0.5,  0.5,  0.5,
		0.5,  0.5,  0.5,
		-0.5, -0.5, -0.5,
		0.5, -0.5, -0.5,
		-0.5,  0.5, -0.5,
		0.5,  0.5, -0.5,
	};

	const GLuint indices[] = {
		0, 1, 2,
		3, 7, 1,
		5, 4, 7,
		6, 2, 4,
		0, 1
	};

	Shader vertex = { GL_VERTEX_SHADER, "vertex.glsl" };
	Shader fragment = { GL_FRAGMENT_SHADER, "fragment.glsl" };
	program.addShader({ vertex, fragment });

	// OPTION #1
	vao.bind();
	vbo.setData(positions, sizeof(positions),GL_STATIC_DRAW);
	ebo.setData(indices, sizeof(indices),GL_STATIC_DRAW);
	vao.setVertexAttrib(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (GLvoid*)0);
	vao.unbind();

	// OPTION #2
	/*vao.load([&]() {
		vbo.setData(positions, sizeof(positions), GL_STATIC_DRAW);
		ebo.setData(indices, sizeof(indices), GL_STATIC_DRAW);
		vao.setPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (GLvoid*)0);
	});*/

	glEnable(GL_DEPTH_TEST);

	pyramid.updateSize(15);

	//input = getWindow().getInput();
}

void Game::update(double time) {
	GLfloat cameraSpeed = 0.25f;

	if (inputManager.getKeyState(GLFW_KEY_A) == ngengine::input::KeyState::Pressed) {
		std::cout << "WOOOOOOOOOOW" << std::endl;
	}
	//if (input.keyPressed(GLFW_KEY_W))
	//	camera.changePos(camera.getPos() + cameraSpeed * camera.getFront());
}

void Game::render(double time) {
	static const GLfloat backColor[] = { 0.2f, 0.3f, 0.5f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, backColor);
	glClear(GL_DEPTH_BUFFER_BIT);

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	camera.setPosition(glm::vec3(0.0f, 0.0f, 5.0f));
	camera.update();

	view = camera.getLookAt();

	projection = glm::perspective(glm::radians(45.0f), 640.0f /  480.0f, 0.1f, 100.0f);

	GLint viewLoc = program.getUniformLocation("view");
	GLint projLoc = program.getUniformLocation("projection");
	GLint modelLoc = program.getUniformLocation("model");

	// OPTION #1
	//program.setUniform(viewLoc, glm::value_ptr(view));
	// OPTION #2
	//program.setUniform(viewLoc, view);

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	program.useProgram();
	vao.bind();

	for (int i = 0; i < pyramid.getSize(); i++) {
		for (int j = 0; j < pyramid.getSize(); j++)
		{
			glm::mat4 model;
			model = glm::translate(model, pyramid.pyramidPosition[i][j]);
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			glDrawElements(GL_TRIANGLE_STRIP, 36, GL_UNSIGNED_INT, 0);
		}
	}

	vao.unbind();
}

void Game::shutdown() {

}