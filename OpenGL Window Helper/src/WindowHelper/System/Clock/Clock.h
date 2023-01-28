#pragma once

namespace jf
{
	class Clock
	{
	public:
		Clock();

		double getSeconds();
		double reset();
	private:
		double m_lastReset;
	};
}