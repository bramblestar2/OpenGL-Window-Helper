#include "Window.h"



namespace jf
{
	Window::Window(const glm::vec2& window_size, std::string title, 
				   jf::ContextSettings settings)
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);


		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

		settings.setHints();

		m_window = glfwCreateWindow(window_size.x, window_size.y, title.c_str(), NULL, NULL);
		setContextCurrent();

		//Set up event handler
		event_handler.setWindowCallbacks(m_window);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
	}

	void Window::setContextCurrent()
	{
		glfwMakeContextCurrent(m_window);
	}

	void Window::setPosition(const glm::vec2& position)
	{
		glfwSetWindowPos(m_window, position.x, position.y);
	}

	void Window::setSize(const glm::vec2& size)
	{
		glfwSetWindowSize(m_window, size.x, size.y);
	}

	void Window::close()
	{
		glfwSetWindowShouldClose(m_window, 1);
	}

	bool Window::pollEvent(Event& event)
	{
		glfwPollEvents();

		return handleEvents(event);
	}

	bool Window::waitEvent(Event& event)
	{
		glfwWaitEvents();

		return handleEvents(event);
	}
	
	GLFWwindow* Window::getWindow()
	{
		return m_window;
	}

	glm::vec2 Window::getPosition() const
	{
		glm::vec<2, int, glm::packed_highp> position;
		glfwGetWindowPos(m_window, &position.x, &position.y);
		return glm::vec2(position);
	}

	glm::vec2 Window::getSize() const
	{
		glm::vec<2, int, glm::packed_highp> size;
		glfwGetWindowSize(m_window, &size.x, &size.y);
		return glm::vec2(size);
	}

	bool Window::isOpen()
	{
		return !glfwWindowShouldClose(m_window);
	}

	void Window::clear(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	void Window::clear(const float r, const float g, const float b, const float a)
	{
		this->clear(glm::vec4(r,g,b,a));
	}

	void Window::clear()
	{
		this->clear(glm::vec4(0, 0, 0, 1));
	}
	
	void Window::display()
	{
		glfwSwapBuffers(m_window);
	}

	bool Window::handleEvents(Event& event)
	{
		if (!event_handler.isEmpty())
		{
			event_handler.pop_event();
			event = event_handler.top_event();

			return true;
		}
		else
			return false;
	}
}