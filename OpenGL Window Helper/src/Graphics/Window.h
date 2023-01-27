#pragma once
#include "../Setup.h"
#include <string>

namespace jf
{
	class Window
	{
	public:
		Window(const glm::vec2& window_size, std::string title);
		~Window();

		void setContextCurrent();
		void close();

		bool isOpen();

	private:
		GLFWwindow* m_window;
	};
}