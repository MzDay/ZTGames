#include "ngengine.h"
#include "PhysicalEntity.h"

namespace ngengine {
	namespace physics {

		PhysicalEntity::PhysicalEntity()
		{
			node = new PhysicalNode();
		}

		PhysicalNode* PhysicalEntity::getNode()
		{
			return node;
		}

		void PhysicalEntity::replaceNode(PhysicalNode* newNode)
		{
			node = newNode;
		}
	}
}
