#pragma once

namespace jf
{
	class Clock
	{
	public:
		Clock();

		float getSeconds();
		float reset();
	private:
		float m_lastReset;
	};
}