#include "Window.h"

namespace ns
{

Window::Window(std::string title, ns::Dim2<int> dimensions)
    : title{title},
      Frame{dimensions},
      window{nullptr}
{ }

Window::~Window()
{ }

bool Window::initialize()
{
    bool success { true };

    // glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        // Initialization failed.
    }

    window = glfwCreateWindow(dimensions.w, dimensions.h, title.c_str(), NULL, NULL);

    if (!window)
    {
        // Window or OpenGL context creation failed.
    }

    glfwMakeContextCurrent(window);

    // gladLoadGL(glfwGetProcAddress);

    // glfwSetKeyCallback(window, key_callback);

    // glfwSetFramebufferSizeCallback(..., framebufferSize_callback);

    return success;
}

bool Window::shutdown()
{
    bool success = true;

    glfwDestroyWindow(window);

    glfwTerminate();

    return success;
}

bool Window::isOpen() const
{
    return windowOpen;
}

void Window::update()
{
    if (glfwWindowShouldClose(window))
    {
        windowOpen = false;
    }
    else
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
    }
}

}