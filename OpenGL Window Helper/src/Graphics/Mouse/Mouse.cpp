#include "Mouse.h"

namespace jf
{
    void Mouse::setPosition(const glm::vec2& position)
    {
        glfwSetCursorPos(glfwGetCurrentContext(), position.x, position.y);
    }

    glm::vec2 Mouse::getPosition()
    {
        GLFWwindow* window = glfwGetCurrentContext();
        glm::vec<2, double, glm::packed_highp> mousePos;
        glfwGetCursorPos(window, &mousePos.x, &mousePos.y);
        
        glm::vec<2, int, glm::packed_highp> windowPos;
        glfwGetWindowPos(window, &windowPos.x, &windowPos.y);

        return glm::vec2(mousePos) + glm::vec2(windowPos);
    }
    glm::vec2 Mouse::getPosition(GLFWwindow* window)
    {
        glm::vec<2, double, glm::packed_highp> pos;
        glfwGetCursorPos(window, &pos.x, &pos.y);
        return glm::vec2();
    }
}