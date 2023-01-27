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
        glm::vec<2, double, glm::packed_highp> pos;
        glfwGetCursorPos(window, &pos.x, &pos.y);
        return glm::vec2(pos);
    }
    glm::vec2 Mouse::getPosition(GLFWwindow* window)
    {
        glm::vec<2, double, glm::packed_highp> pos;
        glfwGetCursorPos(window, &pos.x, &pos.y);
        return glm::vec2();
    }
}