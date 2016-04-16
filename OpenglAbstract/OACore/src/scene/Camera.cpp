#include "ngengine.h"
#include "Camera.h"

namespace ngengine {
	namespace scene {

		Camera::Camera() :
			up(0.0f, 1.0f, 0.0f),
			sensetivity(0.25f),
			fov(45.0f),
			ratio(1.0f),
			near(0.1f),
			far(100.0f)
		{
			updateProjection();
			updateFront();
			update();
		}

#pragma region Setters

		void Camera::setPosition(glm::vec3 cameraPosition)
		{
			node->position = cameraPosition;
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
			node->orientation.yaw = cameraYaw;
			updateFront();
		}

		void Camera::setPitch(float cameraPitch)
		{
			node->orientation.pitch = cameraPitch;
			updateFront();
		}

		void scene::Camera::setFOV(float fieldOfView)
		{
			fov = fieldOfView;
			updateProjection();
		}

		void scene::Camera::setRatio(float viewRatio)
		{
			ratio = viewRatio;
			updateProjection();
		}

		void scene::Camera::setNearClipSpace(float nearClipSapce)
		{
			near = nearClipSapce;
			updateProjection();
		}

		void scene::Camera::setFarClipSpace(float farClipSpace)
		{
			far = farClipSpace;
			updateProjection();
		}

#pragma endregion

#pragma region Getters

		glm::mat4 Camera::getCameraMatrix() const
		{
			return projection * lookAt ;
		}

		glm::vec3 Camera::getPosition() const
		{
			return node->position;
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
			return node->orientation;
		}

#pragma endregion

#pragma region Public Methods

		void Camera::update()
		{
			lookAt = glm::lookAt(node->position, node->position + front, up);
		}

		void Camera::addToYaw(float yawOffset)
		{
			node->orientation.yaw += yawOffset;
			updateFront();
		}

		void Camera::addToYawInRange(float yawOffset, float maxYaw, float minYaw)
		{
			node->orientation.yaw += yawOffset;

			if (node->orientation.pitch > maxYaw)
				node->orientation.pitch = maxYaw;
			if (node->orientation.pitch < minYaw)
				node->orientation.pitch = minYaw;

			updateFront();
		}

		void Camera::addToPitch(float pitchOffset)
		{
			node->orientation.pitch += pitchOffset;
			updateFront();
		}

		void Camera::addToPitchInRange(float pitchOffset, float maxPitch, float minPitch)
		{
			node->orientation.pitch += pitchOffset;

			if (node->orientation.pitch > maxPitch)
				node->orientation.pitch = maxPitch;
			if (node->orientation.pitch < minPitch)
				node->orientation.pitch = minPitch;

			updateFront();
		}

		void Camera::addToPosition(glm::vec3 positionOffset)
		{
			node->position += positionOffset;
		}

		void Camera::addToPositionRelativeToCameraFront(glm::vec3 positionOffset)
		{
			node->position += positionOffset.z * front;
			node->position += positionOffset.y * up;
			node->position += positionOffset.x * glm::normalize(glm::cross(front, up));
		}

		void Camera::addToPositionRelativeToCameraPlaneAndLookAt(glm::vec3 positionOffset)
		{
			glm::vec3 xCross = glm::cross(front, up);
			node->position += positionOffset.x * xCross;
			node->position += positionOffset.z * glm::normalize(glm::cross(up, xCross));
		}

#pragma endregion

#pragma region Private Methods

		void Camera::updateFront()
		{
			glm::vec3 cameraFront;
			cameraFront.x = cos(glm::radians(node->orientation.yaw)) * cos(glm::radians(node->orientation.pitch));
			cameraFront.y = sin(glm::radians(node->orientation.pitch));
			cameraFront.z = sin(glm::radians(node->orientation.yaw)) * cos(glm::radians(node->orientation.pitch));
			front = glm::normalize(cameraFront);
		}

		void scene::Camera::updateProjection()
		{
			projection = glm::perspective(glm::radians(fov), ratio, near, far);
		}

#pragma endregion

		Camera::~Camera()
		{
		}
	}
}