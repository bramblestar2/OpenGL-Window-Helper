#include "BetterWindow.h"
#include <thread>
#include <iostream>

BetterWindow::BetterWindow()
{
	initWindow();

	if (glewInit() != GLEW_OK)
		return;

	jf::Image image;
	image.loadFromFile("src/test.png");


	glfwSetWindowIcon(**m_window, 1, *image);
}


BetterWindow::~BetterWindow()
{
	if (m_window != nullptr)
		delete m_window;
}


void BetterWindow::run()
{
	while (m_window->isOpen())
	{
		update();
		updateDT();
		updateEvents();
		render();
	}
}


void BetterWindow::update()
{
}

void BetterWindow::updateDT()
{
	m_deltaTime = m_clock.reset();
}


void BetterWindow::updateEvents()
{
	while (m_window->pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case jf::Event::KEY_EVENT:

			switch (m_event.keys.action)
			{
			case GLFW_PRESS:
				switch (m_event.keys.key)
				{
				case GLFW_KEY_ESCAPE:
					m_window->close();
					break;
				}
				break;
			}
			break;
		}
	}
}


void BetterWindow::render()
{
	m_window->clear();

	float time = glfwGetTime();
	float x = abs(sin(time));
	float y = abs(cos(time));
	float xx = (sin(time) * 5);
	float yy = (cos(time) * 5);

	glm::vec2 mouse_pos = jf::Mouse::getPosition(**m_window);

	glBegin(GL_QUADS);
	
	glColor3f(x, y, 1 / (x + y));
	glVertex2f(-0.5f + (sin(time + xx)), -0.5f + (cos(time + yy)));
	glVertex2f(-0.5f + (sin(time + xx)),  0.5f + (cos(time + yy)));
	glVertex2f(0.5f  + (sin(time + xx)),  0.5f + (cos(time + yy)));
	glVertex2f(0.5f  + (sin(time + xx)), -0.5f + (cos(time + yy)));

	glEnd();

	m_window->display();
}


void BetterWindow::initWindow()
{
	jf::ContextSettings settings;
	m_window = new jf::Window(glm::vec2(300, 300), "Title", settings /* Optional */);
}
