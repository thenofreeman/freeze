#include "Freeze/Window.h"

namespace ns
{

Window::Window(std::string title, ns::Dim2<int> dimensions)
    : Frame{dimensions},
      title{title},
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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(dimensions.w, dimensions.h, title.c_str(), NULL, NULL);

    if (!window)
    {
        // Window or OpenGL context creation failed.
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return false;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    resizeWindow(window, dimensions.w, dimensions.h);
    glfwSetFramebufferSizeCallback(window, resizeWindow);

    // glfwSetKeyCallback(window, key_callback);

    windowOpen = true;

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

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

void Window::processInput()
{
    processInput(window);
}

void Window::update()
{
    if (glfwWindowShouldClose(window))
    {
        windowOpen = false;
    }
    else
    {
        glfwSwapBuffers(window);
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void Window::resizeWindow(GLFWwindow* window, int width, int height)
{
    if (window) // does nothing, but clears warning for unused param
        glViewport(0, 0, width, height);
}

void Window::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

}