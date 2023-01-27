#include "Window.h"



namespace jf
{
	Window::Window(const glm::vec2& window_size, std::string title)
	{
		m_window = glfwCreateWindow(window_size.x, window_size.y, title.c_str(), NULL, NULL);
		setContextCurrent();
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
	}

	void Window::setContextCurrent()
	{
		glfwMakeContextCurrent(m_window);
	}

	void Window::close()
	{
		glfwSetWindowShouldClose(m_window, 1);
	}
	
	bool Window::isOpen()
	{
		return !glfwWindowShouldClose(m_window);
	}
}