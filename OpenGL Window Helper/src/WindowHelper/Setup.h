#pragma once
#define GLFW_INCLUDE_NONE

#ifdef WIN32
#include <GLFW32/glfw3.h>
#elif _WIN64
#include <GLFW64/glfw3.h>
#endif
#include <GL/glew.h>

#include <glm/glm.hpp>

namespace jf
{
}