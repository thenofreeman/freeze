#pragma once

#include <string>

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

        void update();


    private:
        GLFWwindow* window;

        std::string title;

        bool windowOpen;

};

}