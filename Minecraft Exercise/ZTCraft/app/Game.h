#pragma once

#include <ztengine.h>
#include "../world/World.h"
#include "../world/BlockRenderer.h"
#include "../world/Chunk.h"
#include "Player.h"
#include "glm\gtc\type_ptr.hpp"

using ngengine::graphics::Program;
using ngengine::graphics::Shader;
using ngengine::scene::Camera;

class Game : public ngengine::app::Application {
public:
	 using Application::Application;

public:
	 void render(float delta) override;
	 void update(float delta) override;
	 void startup() override;
	 void shutdown() override;

private:
	 World world;
	 Program program;
	 Player player;
	 Chunk chunk;

	 glm::mat4 projection;
};