#include <iostream>
#include "Graphics/Window.h"

void error_callback(int error, const char* description)
{
	printf(description + '\n');
}

int main()
{
	if (!glfwInit())
		return -1;

	glfwSetErrorCallback(error_callback);


	jf::ContextSettings settings;
	jf::Window window(glm::vec2(300,300), "Title", settings /* Optional */);

	if (glewInit() != GLEW_OK)
		return -1;

	while (window.isOpen())
	{
		jf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case jf::Event::KEY_EVENT:
				switch (event.keys.action)
				{
				case GLFW_PRESS:
					switch (event.keys.key)
					{
					case GLFW_KEY_ESCAPE:
						window.close();
						break;
					}
					break;
				}
				break;
			}
		}

		window.clear();

		float time = glfwGetTime();
		float x = abs(sin(time));
		float y = abs(cos(time));

		glBegin(GL_QUADS);

		glColor3f(x, y, 1/(x * y));
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();

		window.display();
	}

	glfwTerminate();

	return 0;
}