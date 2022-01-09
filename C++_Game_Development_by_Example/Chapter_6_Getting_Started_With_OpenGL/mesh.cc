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

void MeshObject::setQuadData(std::vector<ObjectVertex>& vertices, std::vector<unsigned int>& indices){
	vertices.clear(), indices.clear();
	ObjectVertex v1{
			{-1, -1, 0},
			{0, 0, 1},
			{1, 0, 0},
			{0, 1}
	};
	ObjectVertex v2{
			{-1, 1, 0},
			{0, 0, 1},
			{0, 1, 0},
			{0, 0}
	};
	ObjectVertex v3{
			{1, 1, 0},
			{0, 0, 1},
			{0, 0, 1},
			{1, 0}
	};
	ObjectVertex v4{
			{1, -1, 0},
			{0, 0, 1},
			{1, 0, 1},
			{1, 1}
	};
	indices = {
			0, 1, 2,
			0, 2, 3
	};
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	vertices.push_back(v4);
}

void MeshObject::setCubeData(std::vector<ObjectVertex>& vertices, std::vector<unsigned int>& indices){
	vertices.clear(), indices.clear();
	vertices = {
			//front
			{{-1, -1, 1}, {0, 0, 1}, {1, 0, 0}, {0, 1}},
			{{-1, 1, 1}, {0, 0, 1}, {0, 1, 0}, {0, 0}},
			{{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {1, 0}},
			{{1, -1, 1}, {0, 0, 1}, {1, 0, 1}, {1, 1}},
			//back
			{{1, -1, -1}, {0, 0, -1}, {1, 0, 1}, {0, 1}},
			{{1, 1, -1}, {0, 0, -1}, {0, 1, 1}, {0, 0}},
			{{-1, 1, -1}, {0, 0, -1}, {0, 1, 1}, {1, 0}},
			{{-1, -1, -1}, {0, 0, -1}, {1, 0, 1}, {1, 1}},
			//left
			{{-1, -1, -1}, {-1, 0, 0}, {0, 0, 1}, {0, 1}},
			{{-1, 1, -1}, {-1, 0, 0}, {0, 0, 1}, {0, 0}},
			{{-1, 1, 1}, {-1, 0, 0}, {0, 0, 1}, {1, 0}},
			{{-1, -1, 1}, {-1, 0, 0}, {0, 0, 1}, {1, 1}},
			//right
			{{1, -1, 1}, {1, 0, 0}, {0, 0, 1}, {0, 1}},
			{{1, 1, 1}, {1, 0, 0}, {0, 0, 1}, {0, 0}},
			{{1, 1, -1}, {1, 0, 0}, {0, 0, 1}, {1, 0}},
			{{1, -1, -1}, {1, 0, 0}, {0, 0, 1}, {1, 1}},
			//top
			{{-1, 1, 1}, {0, 1, 0}, {0, 0, 1}, {0, 1}},
			{{-1, 1, -1}, {0, 1, 0}, {0, 0, 1}, {0, 0}},
			{{1, 1, -1}, {0, 1, 0}, {0, 0, 1}, {1, 0}},
			{{1, 1, 1}, {0, 1, 0}, {0, 0, 1}, {1, 1}},
			//bottom
			{{-1, -1, -1}, {0, -1, 0}, {0, 0, 1}, {0, 1}},
			{{-1, -1, 1}, {0, -1, 0}, {0, 0, 1}, {0, 0}},
			{{1, -1, 1}, {0, -1, 0}, {0, 0, 1}, {1, 0}},
			{{1, -1, -1}, {0, -1, 0}, {0, 0, 1}, {1, 1}}
	};
	indices = {
			0, 1, 2,
			2, 3, 0,

			4, 5, 6,
			4, 6, 7,

			8, 9, 10,
			8, 10, 11,

			12, 13, 14,
			12, 14, 15,

			16, 17, 18,
			16, 18, 19,

			20, 21, 22,
			20, 22, 23
	};
}

void MeshObject::setSphereData(std::vector<ObjectVertex>& vertices, std::vector<unsigned int>& indices){
	vertices.clear(), indices.clear();
	float latitudeBands=20, longitudeBands=20, radius=1;
	for(float latitudeNumber=0; latitudeNumber<=latitudeBands; latitudeNumber++){
		float theta = latitudeNumber*3.1415/latitudeBands;
		float sinTheta = std::sin(theta);
	}
}