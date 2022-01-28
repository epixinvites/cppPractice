#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "mesh.h"
#include "shaderLoader.h"
#include "camera.h"

class LightRenderer{
	CameraObject* camera;
	std::vector<ObjectVertex> vertices;
	std::vector<GLuint> indices;
	glm::vec3 position, color;
	GLuint vbo = 0, ebo = 0, vao = 0, program = 0;
public:
	LightRenderer(MeshType meshType, CameraObject* camera);
	void draw();
	void setPosition(const glm::vec3& position);
	void setColor(const glm::vec3& color);
	void setProgram(const GLuint& program);
	glm::vec3 getPosition();
	glm::vec3 getColor();
};
