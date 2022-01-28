#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "light_renderer.h"

const int screenWidth = 800, screenHeight = 600;

void renderScene(LightRenderer* light){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(32/255.0, 32/255.0, 32/255.0, 1);
	light->draw();
}

void initGame(CameraObject* camera, LightRenderer* light){
	glEnable(GL_DEPTH_TEST);
	shaderLoader shader;
	GLuint flatShaderProgram = shader.createProgram("res/shaders/flatModel.vs", "res/shaders/flatModel.fs");
	light->setProgram(flatShaderProgram);
	light->setPosition(glm::vec3{0, 0, 0});
}

int main(){
	glfwInit();
	GLFWwindow* window=glfwCreateWindow(screenWidth, screenHeight, "OpenGL Window", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glewInit();
	CameraObject* camera = new CameraObject(45, screenWidth, screenHeight, 0.1, 100, glm::vec3{0, 4, 6});
	LightRenderer* light = new LightRenderer(MeshType::kTriangle, camera);
	initGame(camera, light);
	while(!glfwWindowShouldClose(window)){
		renderScene(light);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	delete camera, light;
}
