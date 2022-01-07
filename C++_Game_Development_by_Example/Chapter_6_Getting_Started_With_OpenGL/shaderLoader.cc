#include "shaderLoader.h"
#include <fstream>
#include <vector>

std::string shaderLoader::readShader(const std::string& filename){
	std::string shaderCode;
	std::ifstream shaderFile{filename, std::ios::in};
	if(!shaderFile.good()){
		throw std::runtime_error{"Unable to open shader file: " + filename};
	}
	shaderFile.seekg(0, std::ios::end);
	shaderCode.resize(static_cast<unsigned int>(shaderFile.tellg()));
	shaderFile.seekg(0, std::ios::beg);
	shaderFile.read(&shaderCode.at(0), shaderCode.size());
	shaderFile.close();
	return shaderCode;
}

GLuint shaderLoader::createShader(GLenum shaderType, std::string& source, const std::string& shaderName){
	int compileResult = 0;
	GLuint shader = glCreateShader(shaderType);
	const char* shaderCodePtr = source.c_str();
	const int shaderCodeSize = source.length();
	glShaderSource(shader, 1, &shaderCodePtr, &shaderCodeSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);
	if(compileResult == GL_FALSE){
		int errorLogLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLogLength);
		std::vector<char> shaderLog
	}
}