#pragma once
#include <string>

#include "../Setup.h"
#include "ContextSettings/ContextSettings.h"
#include "Events/EventHandler.h"

namespace jf
{
	class Window
	{
	public:
		Window(const glm::vec2& window_size, std::string title, 
			   jf::ContextSettings settings = jf::ContextSettings());
		~Window();

		void setContextCurrent();
		void setPosition(const glm::vec2& position);
		void setSize(const glm::vec2& size);
		void close();

		bool pollEvent(Event& event);
		bool waitEvent(Event& event);

		GLFWwindow* getWindow();
		glm::vec2 getPosition() const;
		glm::vec2 getSize() const;
		bool isOpen();

		void clear(const glm::vec4& color);
		void clear(const float r, const float g, const float b, const float a = 1.f);
		void clear();
		void display();

	private:
		GLFWwindow* m_window;
		EventHandler event_handler;

		bool handleEvents(Event& event);
	};
}