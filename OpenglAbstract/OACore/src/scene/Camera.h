#pragma once

#include "ngengine.h"
#include "utils\Direction.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "utils\Orientation.h"

namespace ngengine {
	namespace scene {

		class Camera
		{
		public:
			Camera();
			~Camera();

			void update();

			void addToYaw(float yawOffset);
			void addToYawInRange(float yawOffset, float maxYaw, float minYaw);
			void addToPitch(float pitchOffset);
			void addToPitchInRange(float pitchOffset, float maxPitch, float minPitch);
			void addToPosition(glm::vec3 positionOffset);
			void addToPositionRelativeToCameraFront(glm::vec3 positionOffset);

			void setPosition(glm::vec3 cameraPosition);
			void setUp(glm::vec3 cameraUp);
			void setSensetivity(float cameraSensetivity);
			void setYaw(float cameraYaw);
			void setPitch(float cameraPitch);

			glm::mat4 getLookAt() const;
			glm::vec3 getPosition() const;
			glm::vec3 getUp() const;
			float getSensetivity() const;
			utils::Orientation getOrientation() const;

		private:
			void updateFront();

		private:
			glm::mat4 lookAt;
			glm::vec3 position;
			glm::vec3 up;
			glm::vec3 front;
			float sensetivity;
			utils::Orientation orientation;
		};
	}
}