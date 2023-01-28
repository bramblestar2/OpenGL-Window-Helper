#include <iostream>
#include "BetterWindow/BetterWindow.h"

void error_callback(int error, const char* description)
{
	std::cout << description << "\n";
}

int main()
{
	if (!glfwInit())
		return -1;

	glfwSetErrorCallback(error_callback);

	BetterWindow window;

	window.run();

	glfwTerminate();

	return 0;
}
