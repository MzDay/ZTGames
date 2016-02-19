#pragma once
#include "Application.h"

class Game : public Application {
public:
	void update(double) override;
	void render(double) override;
	void startup() override;
	void userCallback() override;
};