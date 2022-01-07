#include "camera.h"

CameraObject::CameraObject(GLfloat fov, GLfloat width, GLfloat height, GLfloat nearPlane, GLfloat farPlane, glm::vec3 cameraPosition):cameraPosition{cameraPosition}{
	glm::vec3 cameraFront{0, 0, 0}, cameraUp{0, 1, 0};
	viewMatrix = glm::lookAt(cameraPosition, cameraFront, cameraUp);
	projectionMatrix = glm::perspective(fov, width/height, nearPlane, farPlane);
}

glm::mat4 CameraObject::getViewMatrix(){
	return viewMatrix;
}

glm::mat4 CameraObject::getProjectionMatrix(){
	return projectionMatrix;
}

glm::vec3 CameraObject::getCameraPosition(){
	return cameraPosition;
}