#pragma once

#include "PhysicalNode.h"

namespace ngengine {
	namespace physics {

		class PhysicalEntity {

		public:
			PhysicalEntity();

			PhysicalNode* getNode();
			void replaceNode(PhysicalNode* newNode);

		public:
			PhysicalNode* node;
		};
	}
}