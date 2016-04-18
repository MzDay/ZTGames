#pragma once
#include <deque>
#include "Block.h"
#include "SeedBasedRandom.h"

class World {
public:
	 World() : seed(123){
		  for (float x = 0.0f; x < 100.0f; ++x) {
			   for (float y = 0.0f; y < 10.0f; ++y) {
					for (float z = 0.0f; z < 10.0f; ++z)
					blocks.push_back(new Block(x, y, z));
			   }
		  }
	 }

public:
	 void render(float delta);
	 void update(float delta);

private:
	 std::deque<Block*> blocks;
	 SeedBasedRandom<0, 20> seed;
};
