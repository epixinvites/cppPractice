#include <GL/glew.h>
#include <string>

class shaderLoader{
	static std::string readShader(const std::string& filename);
	GLuint createShader(GLenum shaderType, std::string& source, const std::string& shaderName);
public:
	GLuint createProgram(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);
};