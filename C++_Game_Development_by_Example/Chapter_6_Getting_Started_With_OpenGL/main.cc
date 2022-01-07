#include <GL/glew.h>
#include <GLFW/glfw3.h>

const int screenWidth = 800, screenHeight = 600;

void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(32/255.0, 32/255.0, 32/255.0, 1);
}

int main(){
	glfwInit();
	GLFWwindow* window=glfwCreateWindow(screenWidth, screenHeight, "OpenGL Window", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glewInit();
	while(!glfwWindowShouldClose(window)){
		renderScene();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}