#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>

#include "Dim.h"

namespace ns
{

class Window
{
    public:
        Window(std::string title, Dim2<int> dimensions);
        virtual ~Window();

        bool initialize();
        bool shutdown();
    
    public:

    private:

    private:
        std::string title;
        Dim2<int> dimensions;

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* screen;

};

}