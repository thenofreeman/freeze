#include "RectangleShape.h"

namespace ns
{

RectangleShape::RectangleShape(ns::Rect<int> rect, ns::Color color)
    : Shape{color},
      body{rect}
{ }

RectangleShape::~RectangleShape()
{ }

void RectangleShape::update(const int& deltaTime)
{ }

void RectangleShape::draw(SDL_Renderer*& renderer) const
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, (const SDL_Rect*) &body);
}

}