#include "Clock.h"
#include "../../Setup.h"

namespace jf
{
	Clock::Clock()
	{
		m_lastReset = glfwGetTime();
	}

	float Clock::getSeconds()
	{
		return glfwGetTime() - m_lastReset;
	}

	float Clock::reset()
	{
		float temp_seconds = m_lastReset;
		m_lastReset = glfwGetTime();
		return temp_seconds;
	}
}