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

	program.createProgram();
	Shader vertex = { GL_VERTEX_SHADER, "vertex.glsl" };
	Shader fragment = { GL_FRAGMENT_SHADER, "fragment.glsl" };
	program.addShader({ vertex, fragment });

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	glEnable(GL_DEPTH_TEST);

	// Camera init
	cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	// Init keys
	keysState = { false };

	mouseLastX = getWindowSize().width / 2;
	mouseLastY = getWindowSize().height / 2;
	firstMouse = true;

	cameraYaw = -90.0f;
	cameraPitch = 0.0f;

	pyramid.updateSize(15);
}

void Game::update(double time) {
	GLfloat cameraSpeed = 0.25f;

	if (keysState[GLFW_KEY_W])
		cameraPos += cameraSpeed * cameraFront;
	if (keysState[GLFW_KEY_S])
		cameraPos -= cameraSpeed * cameraFront;
	if (keysState[GLFW_KEY_A])
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (keysState[GLFW_KEY_D])
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (keysState[GLFW_KEY_EQUAL])
		pyramid.updateSize(pyramid.getSize() + 2);
	if (keysState[GLFW_KEY_MINUS])
		pyramid.updateSize(pyramid.getSize() - 2);
}

void Game::render(double time) {
	static const GLfloat backColor[] = { 0.2f, 0.3f, 0.5f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, backColor);
	glClear(GL_DEPTH_BUFFER_BIT);

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	projection = glm::perspective(glm::radians(45.0f), static_cast<GLfloat>(getWindowSize().width) / static_cast<GLfloat>(getWindowSize().height), 0.1f, 100.0f);

	GLint viewLoc = glGetUniformLocation(program.getProgram(), "view");
	GLint projLoc = glGetUniformLocation(program.getProgram(), "projection");
	GLint modelLoc = glGetUniformLocation(program.getProgram(), "model");

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	program.useProgram();
	glBindVertexArray(vao);
	for (int i = 0; i < pyramid.getSize(); i++) {
		for (int j = 0; j < pyramid.getSize(); j++)
		{
			glm::mat4 model;
			model = glm::translate(model, pyramid.pyramidPosition[i][j]);
			//GLfloat angle = 20.0f * i;
			//model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			glDrawElements(GL_TRIANGLE_STRIP, 36, GL_UNSIGNED_INT, 0);
		}
	}
	glBindVertexArray(0);
}

void Game::shutdown() {

}

void Game::keyCallback(int key, int action) {

	if (action == GLFW_PRESS)
		keysState[key] = true;
	else if (action == GLFW_RELEASE)
		keysState[key] = false;
}

void Game::mouseCallback(double xPos, double yPos)
{
	if (firstMouse)
	{
		mouseLastX = xPos;
		mouseLastY = yPos;
		firstMouse = false;
	}

	GLfloat xOffset = xPos - mouseLastX;
	GLfloat yOffset = mouseLastY - yPos; // Reversed since y-coordinates range from bottom to top
	mouseLastX = xPos;
	mouseLastY = yPos;

	GLfloat sensitivity = 0.05f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	cameraYaw += xOffset;
	cameraPitch += yOffset;

	if (cameraPitch > 89.0f)
		cameraPitch = 89.0f;
	if (cameraPitch < -89.0f)
		cameraPitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
	front.y = sin(glm::radians(cameraPitch));
	front.z = sin(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
	cameraFront = glm::normalize(front);
}
