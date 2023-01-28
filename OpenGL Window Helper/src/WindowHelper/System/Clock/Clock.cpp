#include "Clock.h"
#include "../../Setup.h"

namespace jf
{
	Clock::Clock()
	{
		m_lastReset = glfwGetTime();
	}

	double Clock::getSeconds()
	{
		return glfwGetTime() - m_lastReset;
	}

	double Clock::reset()
	{
		double temp_seconds = m_lastReset;
		m_lastReset = glfwGetTime();
		return temp_seconds;
	}
}