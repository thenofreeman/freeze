#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "AssetManager.h"
#include "Texture.h"
#include "Vector.h"

namespace ns
{

class Sprite
{
    public:
        Sprite(std::string path);
        Sprite(Texture* texture, const SDL_Rect& clipping);
        virtual ~Sprite();

        void update(const int& deltaTime) const;
        void draw(SDL_Renderer*& renderer) const;

        void setPosition(Vector2<int> newPosition);
        void setDimensions(Vector2<int> newDimensions);
        Vector2<int> getPosition() const;
        Vector2<int> getDimensions() const;

    public:

    private:

    private:
        ns::Texture* texture;
        SDL_Rect clipping;

        Vector2<int> position;
        Vector2<int> dimensions;

    private:
        Sprite() = delete;

};

}