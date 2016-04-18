#include "World.h"

void World::render(float delta) {
	 for (unsigned int i = 0; i < blocks.size(); ++i) {
		  blocks[i]->update(delta);
		  blocks[i]->render(delta);
	 }
}

void World::update(float delta) {
}