#include "World.h"

void World::render(double delta) {
	 for (unsigned int i = 0; i < blocks.size(); ++i) {
		  blocks[i]->update(delta);
		  blocks[i]->render(delta);
	 }
}

void World::update(double delta) {
}