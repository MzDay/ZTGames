#ifndef GAME_H
#define GAME_H

#include "Application.h"

#include <cmath>
#include <iomanip>
#include <thread>
#include "Program.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

using namespace std::literals;

class Game : public Application {
public:
	void update(double) override;
	void render(double) override;
	void startup() override;
	void shutdown() override;
	void onResize(int w, int h);
	void userCallback() override;

private:
	GLuint buf;
	GLuint vao;
	Program program;

	GLint           mv_location;
	GLint           proj_location;

	float           aspect;
	glm::mat4       proj_matrix;
};

#endif