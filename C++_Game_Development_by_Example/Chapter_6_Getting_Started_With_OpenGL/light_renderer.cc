#include "light_renderer.h"

lightRenderer::lightRenderer(MeshType meshType, CameraObject* camera){
	this->camera = camera;
	switch(meshType){
		case kTriangle:
			MeshObject::setTriData(vertices, indices);
			break;
		case kQuad:
			MeshObject::setQuadData(vertices, indices);
			break;
		case kCube:
			MeshObject::setCubeData(vertices, indices);
			break;
		case kSphere:
			MeshObject::setSphereData(vertices, indices);
			break;
	}
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ObjectVertex)*vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ObjectVertex), static_cast<GLvoid*>(nullptr));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ObjectVertex), reinterpret_cast<void*>(offsetof(ObjectVertex, ObjectVertex::color)));
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}