#include "mesh.h"

ObjectVertex::ObjectVertex(glm::vec3 pos, glm::vec3 normal, glm::vec3 color, glm::vec2 texCoordinates):pos{pos}, normal{normal}, color{color}, texCoordinates{texCoordinates}{}

void MeshObject::setTriData(std::vector<ObjectVertex>& vertices, std::vector<unsigned int>& indices){
	vertices.clear(), indices.clear();
	ObjectVertex v1{
			{0, 1, 0},
			{0, 0, 1},
			{1, 0, 0},
			{0, 1}
	};
	ObjectVertex v2{
			{1, 1, 0},
			{0, 0, 1},
			{0, 1, 0},
			{0, 0}
	};
	ObjectVertex v3{
			{-1, 1, 0},
			{0, 0, 1},
			{0, 1, 0},
			{1, 0}
	};
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	for(int i = 0; i<vertices.size(); i++){
		indices.push_back(i);
	}
}