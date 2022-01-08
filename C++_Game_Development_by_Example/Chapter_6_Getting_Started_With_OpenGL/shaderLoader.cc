#include "shaderLoader.h"
#include <fstream>
#include <vector>
#include <string>

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
		std::vector<char> shaderLog(errorLogLength);
		glGetShaderInfoLog(shader, errorLogLength, nullptr, &shaderLog[0]);
		std::string errorMessage = "Error compiling shader "+shaderName+"\n"+&shaderLog[0]+"\n";
		throw std::runtime_error{errorMessage};
	}
	return shader;
}

GLuint shaderLoader::createProgram(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename){
	std::string vertexShaderCode=readShader(vertexShaderFilename), fragmentShaderCode=readShader(fragmentShaderFilename);
	GLuint vertexShader=createShader(GL_VERTEX_SHADER, vertexShaderCode, "Vertex shader"), fragmentShader=createShader(GL_FRAGMENT_SHADER, fragmentShaderCode, "Fragment shader");
	int linkResult{0};
	GLuint program=glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);
	if(linkResult==GL_FALSE){
		int errorLogLength{0};
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &errorLogLength);
		std::vector<char> programLog(errorLogLength);
		glGetProgramInfoLog(program, errorLogLength, nullptr, &programLog[0]);
		std::string errorMessage = "Shader link failed\n"+&program[0];
		throw std::runtime_error{errorMessage};
	}
	return program;
}