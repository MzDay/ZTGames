#pragma once

namespace ngengine {
	namespace entityProperties {

		class IEntityProperty {

		public:
			virtual void update(float deltaTime) = 0;
		};
	}
}