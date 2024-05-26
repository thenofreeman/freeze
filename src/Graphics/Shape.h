#pragma once

#include <SDL2/SDL.h>

#include "Color.h"

namespace ns
{

class Shape
{
    protected:
        Shape(ns::Color color);
        virtual ~Shape();

        virtual void update(const int& deltaTime) = 0;
        virtual void draw(SDL_Renderer*& renderer) const = 0;

    protected:
        ns::Color color;

    public:
        Shape() = delete;

};

}