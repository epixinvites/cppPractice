#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "mesh.h"
#include "shaderLoader.h"
#include "camera.h"

class lightRenderer{
	CameraObject* camera;
	std::vector<ObjectVertex> vertices;
	std::vector<GLuint> indices;
	glm::vec3 position, color;
	GLuint VBO, EBO, VAO, program;
public:
	lightRenderer(MeshType meshType, CameraObject* camera);
	void draw();
	void setPosition(glm::vec3 _position);
	void setColor(glm::vec3 _color);
	void setProgram(GLuint _program);
	glm::vec3 getPosition();
	glm::vec3 getColor();
};
