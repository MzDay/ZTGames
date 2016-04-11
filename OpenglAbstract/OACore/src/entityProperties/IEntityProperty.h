#pragma once

namespace ngengine {
	namespace entityProperties {

		class IEntityProperty {

		public:
			virtual void update(double deltaTime) = 0;
		};
	}
}