#include "ContextSettings.h"
#include "../../Setup.h"

namespace jf 
{
	ContextSettings::ContextSettings(const int depthBits, const int stencilBits, 
		const int antiAliasing, const int minorVersion, const int majorVersion)
	{
		m_depthBits = depthBits;
		m_stencilBits = stencilBits;
		m_antiAliasing = antiAliasing;
		m_minorVersion = minorVersion;
		m_majorVersion = majorVersion;
	}

	ContextSettings::ContextSettings()
	{
	}

	void ContextSettings::setHints()
	{
		glfwWindowHint(GLFW_DEPTH_BITS, m_depthBits);
		glfwWindowHint(GLFW_DEPTH_BITS, m_stencilBits);
		glfwWindowHint(GLFW_SAMPLES, m_antiAliasing);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_minorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_majorVersion);

		glfwWindowHint(GLFW_RESIZABLE, m_resizable);
		glfwWindowHint(GLFW_DECORATED, m_decorated);
		glfwWindowHint(GLFW_FOCUSED, m_focused);
		glfwWindowHint(GLFW_FLOATING, m_floating);
		glfwWindowHint(GLFW_MAXIMIZED, m_maximized);
		glfwWindowHint(GLFW_CENTER_CURSOR, m_centerCursor);
		glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, m_transparent);
		glfwWindowHint(GLFW_FOCUS_ON_SHOW, m_focusOnShow);
		glfwWindowHint(GLFW_SCALE_TO_MONITOR, m_scaleToMonitor);
	}
}