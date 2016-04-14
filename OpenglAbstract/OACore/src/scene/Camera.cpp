#include "ngengine.h"
#include "Camera.h"

namespace ngengine {
	namespace scene {
		Camera::Camera() :
			position(0.0f, 0.0f, 0.0f),
			up(0.0f, 1.0f, 0.0f),
			orientation(-90.0f, 0.0f, 0.0f),
			sensetivity(0.25f)
		{
			updateFront();
			update();
		}

#pragma region Setters

		void Camera::setPosition(glm::vec3 cameraPosition)
		{
			position = cameraPosition;
		}

		void Camera::setUp(glm::vec3 cameraUp)
		{
			up = cameraUp;
		}

		void Camera::setSensetivity(float cameraSensetivity)
		{
			sensetivity = cameraSensetivity;
		}

		void Camera::setYaw(float cameraYaw)
		{
			orientation.yaw = cameraYaw;
			updateFront();
		}

		void Camera::setPitch(float cameraPitch)
		{
			orientation.pitch = cameraPitch;
			updateFront();
		}

#pragma endregion

#pragma region Getters

		glm::mat4 Camera::getLookAt() const
		{
			return lookAt;
		}

		glm::vec3 Camera::getPosition() const
		{
			return position;
		}

		glm::vec3 Camera::getUp() const
		{
			return up;
		}

		float Camera::getSensetivity() const
		{
			return sensetivity;
		}

		utils::Orientation Camera::getOrientation() const
		{
			return orientation;
		}

#pragma endregion

#pragma region Public Methods

		void Camera::update()
		{
			lookAt = glm::lookAt(position, position + front, up);
		}

		void Camera::addToYaw(float yawOffset)
		{
			orientation.yaw += yawOffset;
			updateFront();
		}

		void Camera::addToYawInRange(float yawOffset, float maxYaw, float minYaw)
		{
			orientation.yaw += yawOffset;

			if (orientation.pitch > maxYaw)
				orientation.pitch = maxYaw;
			if (orientation.pitch < minYaw)
				orientation.pitch = minYaw;

			updateFront();
		}

		void Camera::addToPitch(float pitchOffset)
		{
			orientation.pitch += pitchOffset;
			updateFront();
		}

		void Camera::addToPitchInRange(float pitchOffset, float maxPitch, float minPitch)
		{
			orientation.pitch += pitchOffset;

			if (orientation.pitch > maxPitch)
				orientation.pitch = maxPitch;
			if (orientation.pitch < minPitch)
				orientation.pitch = minPitch;

			updateFront();
		}

		void Camera::addToPosition(glm::vec3 positionOffset)
		{
			position += positionOffset;
		}

		void Camera::addToPositionRelativeToCameraFront(glm::vec3 positionOffset)
		{
			position += positionOffset.z * front;
			position += positionOffset.y * up;
			position += positionOffset.x * glm::normalize(glm::cross(front, up));
		}

		void Camera::addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3 positionOffset)
		{
			glm::vec3 xCross = glm::cross(front, up);
			position += positionOffset.x * xCross;
			position += positionOffset.z * glm::normalize(glm::cross(up, xCross));
		}

#pragma endregion

#pragma region Private Methods

		void Camera::updateFront()
		{
			glm::vec3 cameraFront;
			cameraFront.x = cos(glm::radians(orientation.yaw)) * cos(glm::radians(orientation.pitch));
			cameraFront.y = sin(glm::radians(orientation.pitch));
			cameraFront.z = sin(glm::radians(orientation.yaw)) * cos(glm::radians(orientation.pitch));
			front = glm::normalize(cameraFront);
		}

#pragma endregion

		Camera::~Camera()
		{
		}
	}
}