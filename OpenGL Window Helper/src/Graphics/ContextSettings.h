#pragma once

namespace jf
{
	class ContextSettings
	{
	public:
		ContextSettings(const int depthBits, const int stencilBits, const int antiAliasing, 
						const int minorVersion, const int majorVersion);
		ContextSettings();

		int m_depthBits;
		int m_stencilBits;
		int m_antiAliasing;
		int m_minorVersion;
		int m_majorVersion;
	};
}