#include "Shape.h"

#include <SDL2/SDL.h>

#include "Coor.h"

class LineShape : public ns::Shape
{
    public:
        LineShape(ns::Coor2<int> from, ns::Coor2<int> to, ns::Color color);
        virtual ~LineShape();

        virtual void update(const int& deltaTime);
        virtual void draw(SDL_Renderer*& renderer) const;
    
    public:

    private:

    private:
        ns::Coor2<int> from;
        ns::Coor2<int> to;

    public:
        LineShape() = delete;

};