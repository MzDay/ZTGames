#pragma once
#include <vector>
#include "BlockRenderer.h"
#include "SeedBasedRandom.h"

class World {
public:
	World() : seed(123) {
		for (float x = 0.0f; x < 1000.0f; ++x) {
			for (float z = 0.0f; z < 500.0f; ++z) {
				Pos3D pos;
				pos.x = x;
				pos.y = cos(x) * sin(z);
				pos.z = z;
				blocks.push_back(Block(pos));
			}
		}
	}

public:
	void render(float delta);
	void update(float delta);

private:
	std::vector<Block> blocks;
	BlockRenderer blockRenderer;
	SeedBasedRandom<0, 20> seed;
};
