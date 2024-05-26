#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "Coor.h"
#include "Dim.h"

namespace ns
{

class Texture
{
    public:
        Texture();
        virtual ~Texture();

        bool load(std::string path);

        void update(const int& deltaTime) const;
        void draw(SDL_Renderer*& renderer) const;
        void draw(SDL_Renderer*& renderer, const Rect& clipping) const;

        void setPosition(Coor2<int> newPosition);
        void setDimensions(Dim2<int> newDimensions);
        void setColor(const Color& color);
        void setBlendMode(const SDL_BlendMode& blending);
        void setTransparency(const Uint8& alpha);

        Vector2<int> getPosition() const;
        Vector2<int> getDimensions() const;

        void free();

    public:

    private:

    private:
        SDL_Texture* texture;

        Coor2<int> position;
        Dim2<int> dimensions;

};

}