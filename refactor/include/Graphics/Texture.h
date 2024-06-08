#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "Color.h"
#include "Coor.h"
#include "Dim.h"
#include "Rect.h"

class Texture
{
    public:
        Texture();
        Texture(std::string path, ns::Dim2<int> dimensions);
        virtual ~Texture();

        bool load(std::string path);

        void update(const int& deltaTime) const;
        void draw(SDL_Renderer*& renderer) const;
        void draw(SDL_Renderer*& renderer, const ns::Rect<int>& clipping) const;

        void setPosition(ns::Coor2<int> newPosition);
        void setDimensions(ns::Dim2<int> newDimensions);
        void setColor(const ns::Color& color);
        void setBlendMode(const SDL_BlendMode& blending);
        void setTransparency(const Uint8& alpha);

        ns::Coor2<int> getPosition() const;
        ns::Dim2<int> getDimensions() const;

        void free();

    public:

    private:

    private:
        SDL_Texture* texture;

        ns::Coor2<int> position;
        ns::Dim2<int> dimensions;

};