#pragma once
#include "../../Setup.h"

namespace jf
{
	class Mouse
	{
	public:
		Mouse();

		void setPosition(const glm::vec2& position);

		static glm::vec2 getPosition();
		static glm::vec2 getPosition(GLFWwindow* window);
	private:
	};
}