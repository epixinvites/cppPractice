#include <vector>
#include <glm/glm.hpp>

enum MeshType{
	kTriangle, kQuad, kCube, kSphere
};

struct ObjectVertex{
	glm::vec3 pos, normal, color;
	glm::vec2 texCoordinates;

	ObjectVertex(glm::vec3& pos, glm::vec3& normal, glm::vec3& color, glm::vec2& texCoordinates);
};

class MeshObject{
public:
	void setTriData(std::vector<ObjectVertex>& vertices, std::vector<unsigned int>& indices);
	void setQuadData(std::vector<ObjectVertex>& vertices, std::vector<unsigned int>& indices);
	void setCubeData(std::vector<ObjectVertex>& vertices, std::vector<unsigned int>& indices);
	void setSphereData(std::vector<ObjectVertex>& vertices, std::vector<unsigned int>& indices);
};