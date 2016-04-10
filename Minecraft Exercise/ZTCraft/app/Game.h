#pragma once

#include <ztengine.h>

class Game : public ngengine::app::Application {
public:
	 using Application::Application;

public:
	 void render(double delta) override;
	 void update(double delta) override;
	 void startup() override;
	 void shutdown() override;
};