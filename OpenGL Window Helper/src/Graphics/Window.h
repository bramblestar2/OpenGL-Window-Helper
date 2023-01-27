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

		void clear(const glm::vec4& color);
		void clear(const float r, const float g, const float b, const float a = 1.f);
		void clear();
		void display();

	private:
		GLFWwindow* m_window;
	};
}