#include "ngengine.h"
#include "PhysicalNode.h"

namespace ngengine {
	namespace physics {

		PhysicalNode::PhysicalNode() :
			position(0.0f, 0.0f, 0.0f),
			orientation(-90.0f, 0.0f, 0.0f) {
		}
	}
}
