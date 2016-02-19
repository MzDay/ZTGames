#pragma once
#include "Application.h"

class Game : public Application {
public:
	void update() override;
	void render() override;
	void startup() override;
	void userCallback() override;
};