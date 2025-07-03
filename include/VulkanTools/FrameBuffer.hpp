#pragma once
#include <GLFW/glfw3.h>
namespace VKT
{
    auto getFrameBufferSizeChange(GLFWWindow* window, int& width, int& height) -> bool
    {
        if (window->frameBufferSize.x != width || window->frameBufferSize.y != height)
        {
            window->frameBufferSize = {width, height};
            return true;
        }
        return false;
    }
}