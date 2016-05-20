#include "ngengine.h"
#include "PhysicalNode.h"

namespace ngengine {
	namespace physics {

		PhysicalNode::PhysicalNode() :
			position(0.0f, 0.0f, 0.0f),
			orientation(-90.0f, 0.0f, 0.0f),
			size(0.0f, 0.0f, 0.0f),
			boxPosition(0.0f, 0.0f, 0.0f) {
		}

		void PhysicalNode::updateBoxPosition()
		{
			boxPosition = glm::vec3(position.x - size.width / 2, 
				position.y - size.height / 2, 
				position.z - size.depth / 2);
		}
	}
}
