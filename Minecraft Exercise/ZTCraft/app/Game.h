#pragma once

#include <ztengine.h>
#include "../world/World.h"
#include "../world/Block.h"
#include "Player.h"
#include "glm\gtc\type_ptr.hpp"

using ngengine::graphics::Program;
using ngengine::graphics::Shader;
using ngengine::scene::Camera;

class Game : public ngengine::app::Application {
public:
	 using Application::Application;

public:
	 void render(double delta) override;
	 void update(double delta) override;
	 void startup() override;
	 void shutdown() override;

private:
	 World world;
	 Program program;
	 Player player;

	 glm::mat4 projection;
};