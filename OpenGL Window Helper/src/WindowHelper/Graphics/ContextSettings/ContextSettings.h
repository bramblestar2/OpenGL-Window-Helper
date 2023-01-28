#pragma once

namespace jf
{
	class ContextSettings
	{
	public:
		ContextSettings(const int depthBits, const int stencilBits, const int antiAliasing, 
						const int minorVersion, const int majorVersion);
		ContextSettings();

		void setHints();

		int m_depthBits = 24;
		int m_stencilBits = 8;
		int m_antiAliasing = 0;
		int m_minorVersion = 0;
		int m_majorVersion = 2;

		int m_resizable = 1;
		int m_decorated = 1;
		int m_focused = 1;
		int m_floating = 0;
		int m_maximized = 0;
		int m_centerCursor = 0;
		int m_transparent = 0;
		int m_focusOnShow = 0;
		int m_scaleToMonitor = 0;
	};
}