#include <iostream>
#include "Graphics/Window.h"

int main()
{
	if (!glfwInit())
		return -1;

	//GLFWwindow* window = glfwCreateWindow(200, 200, "Title", NULL, NULL);
	//
	//glfwMakeContextCurrent(window);

	jf::Window window(glm::vec2(200,200), "Title");

	if (glewInit() != GLEW_OK)
		return -1;

	//while (!glfwWindowShouldClose(window))
	//{
	//	glClearColor(0.1, 0.1, 0.1, 1);
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//
	//	glBegin(GL_QUADS);
	//
	//	glVertex2f(-0.5f, -0.5f);
	//	glVertex2f(-0.5f, 0.5f);
	//	glVertex2f(0.5f, 0.5f);
	//	glVertex2f(0.5f, -0.5f);
	//
	//	glEnd();
	//
	//	glfwSwapBuffers(window);
	//	glfwPollEvents();
	//}
	
	//glfwDestroyWindow(window);
	//glfwTerminate();

	return 0;
}