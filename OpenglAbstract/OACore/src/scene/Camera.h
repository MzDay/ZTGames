#pragma once

#include "ngengine.h"
#include "utils\Direction.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "utils\Orientation.h"
#include "physics\PhysicalEntity.h"

namespace ngengine {
	namespace scene {

		class Camera : public physics::PhysicalEntity
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
			void addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3 positionOffset);

			void setPosition(glm::vec3 cameraPosition);
			void setUp(glm::vec3 cameraUp);
			void setSensetivity(float cameraSensetivity);
			void setYaw(float cameraYaw);
			void setPitch(float cameraPitch);
			void setFOV(float fieldOfView);
			void setRatio(float viewRatio);
			void setNearClipSpace(float nearClipSapce);
			void setFarClipSpace(float farClipSpace);

			glm::mat4 getCameraMatrix() const;
			glm::vec3 getPosition() const;
			glm::vec3 getUp() const;
			float getSensetivity() const;
			utils::Orientation getOrientation() const;

			glm::vec3 getMovementRelativeToCameraFront(glm::vec3 positionOffset);
			glm::vec3 getMovementRelativeToCameraPlaneAndLookAt(glm::vec3 positionOffset);

		private:
			void updateFront();
			void updateProjection();

		private:
			glm::mat4 lookAt;
			glm::vec3 up;
			glm::vec3 front;
			float sensetivity;

			glm::mat4 projection;
			float fov;
			float ratio;
			float near;
			float far;
		};
	}
}