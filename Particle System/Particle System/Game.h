#ifndef GAME_H
#define GAME_H

#include "Application.h"

#include <cmath>
#include <iomanip>
#include <thread>
#include "Program.h"

using namespace std::literals;

class Game : public Application {
public:
	void update(double) override;
	void render(double) override;
	void startup() override;
	void shutdown() override;
	void userCallback() override;
};

#endif