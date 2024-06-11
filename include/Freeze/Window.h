#pragma once

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Dim.h"
#include "Frame.h"

namespace ns
{

class Window : public ns::Frame
{
    public:
        Window(std::string title, ns::Dim2<int> dimensions);
        virtual ~Window();

        bool initialize();
        bool shutdown();

        bool isOpen() const;
        void processInput();
        void update();

    private:
        static void resizeWindow(GLFWwindow* window, int width, int height);
        static void processInput(GLFWwindow* window);

    private:
        std::string title;

        GLFWwindow* window;
        bool windowOpen;

};

}