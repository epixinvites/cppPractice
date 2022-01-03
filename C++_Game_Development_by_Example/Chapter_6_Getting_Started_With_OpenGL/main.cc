#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(){
	glfwInit();
	GLFWwindow* window=glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
	glfwMakeContextCurrent(window);
	glewInit();
	while(!glfwWindowShouldClose(window)){
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}