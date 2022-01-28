#include "light_renderer.h"

LightRenderer::LightRenderer(MeshType meshType, CameraObject* camera){
	this->camera = camera;
	switch(meshType){
		case kTriangle: MeshObject::setTriData(vertices, indices);
			break;
		case kQuad: MeshObject::setQuadData(vertices, indices);
			break;
		case kCube: MeshObject::setCubeData(vertices, indices);
			break;
		case kSphere: MeshObject::setSphereData(vertices, indices);
			break;
	}
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ObjectVertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ObjectVertex), static_cast<GLvoid*>(nullptr));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ObjectVertex), reinterpret_cast<void*>(offsetof(ObjectVertex, ObjectVertex::color)));
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void LightRenderer::draw(){
	glm::mat4 model = glm::mat4(1);
	model = glm::translate(glm::mat4(1), position);
	glUseProgram(this->program);
	GLint modelLoc = glGetUniformLocation(this->program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glm::mat4 view = camera->getViewMatrix();
	GLint vLoc = glGetUniformLocation(this->program, "view");
	glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(view));
	glm::mat4 proj = camera->getProjectionMatrix();
	GLint pLoc = glGetUniformLocation(this->program, "projection");
	glUniformMatrix4fv(pLoc, 1, GL_FALSE, glm::value_ptr(proj));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}

void LightRenderer::setPosition(const glm::vec3& position){
	this->position = position;
}

void LightRenderer::setColor(const glm::vec3& color){
	this->color = color;
}

void LightRenderer::setProgram(const GLuint& program){
	this->program = program;
}

glm::vec3 LightRenderer::getPosition(){
	return this->position;
}

glm::vec3 LightRenderer::getColor(){
	return this->color;
}
