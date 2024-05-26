#pragma once

#include <SDL2/SDL.h>

#include "Rect.h"
#include "Shape.h"

namespace ns
{

class RectangleShape : public ns::Shape
{
    public:
        RectangleShape(ns::Rect<int> rect, ns::Color color);
        virtual ~RectangleShape();

        virtual void update(const int& deltaTime);
        virtual void draw(SDL_Renderer*& renderer) const;
    
    public:

    private:

    private:
        ns::Rect<int> body;

    public:
        RectangleShape() = delete;

};

}