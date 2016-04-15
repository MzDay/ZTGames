#pragma once
#include <deque>
#include "Block.h"
#include "SeedBasedRandom.h"

class World {
public:
	 World() : seed(123){
		  float start = 1.0f;
		  for (int i = 0; i < 100; ++i) {
			   blocks.push_back(new Block(start++, 4.0f, 1.0f));
		  }
	 }

public:
	 void render(double delta);
	 void update(double delta);

private:
	 std::deque<Block*> blocks;
	 SeedBasedRandom<0, 20> seed;
};
