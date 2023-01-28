#pragma once
#include "WindowHelper/Graphics/Window.h"
#include "WindowHelper/System/Clock/Clock.h"
#include "WindowHelper/Graphics/Mouse/Mouse.h"

//I couldn't think of another name for this class
class BetterWindow
{
public:
	BetterWindow();
	~BetterWindow();

	void run();
	void update();
	void updateDT();
	void updateEvents();
	void render();

private:
	void initWindow();

	jf::Window* m_window;
	jf::Event m_event;

	jf::Clock m_clock;
	double m_deltaTime;
};