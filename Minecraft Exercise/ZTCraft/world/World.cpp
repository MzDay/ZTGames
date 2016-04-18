#include "World.h"

void World::render(float delta) {
	 for (unsigned int i = 0; i < blocks.size(); ++i) {
		 blockRenderer.update(delta, blocks[i]);
		 blockRenderer.render(delta, blocks[i]);
	 }
}

void World::update(float delta) {
}