#include "Texture.h"

#include <SDL2/SDL_image.h>

Texture::Texture()
    : texture{nullptr},
      position{0, 0},
      dimensions{0, 0}
{ }

Texture::Texture(std::string path, ns::Dim2<int> dimensions)
    : texture{nullptr},
      position{0, 0},
      dimensions{dimensions}
{ 
    load(path);
}

Texture::~Texture()
{ 
    free();
}

bool Texture::load(std::string path)
{ 
	bool success = true;

    free();

    SDL_Texture* newTexture = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface)
	{
		std::cerr << "Unable to load texture image " << path << "! SDL Error: " << IMG_GetError() << std::endl;
		success = false;
	}
    else
    {
        SDL_Color& key = gEnvironment.keyingColor;
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, key.r, key.g, key.b));

        newTexture = SDL_CreateTextureFromSurface(gEnvironment.renderer, loadedSurface);
        if (!newTexture)
        {
            std::cerr << "Unable to create texture from image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            dimensions.w = loadedSurface->w;
            dimensions.h = loadedSurface->h;

            texture = newTexture;
        }

        SDL_FreeSurface(loadedSurface);
    }

	return success;
}

void Texture::update(const int& deltaTime) const
{ }

void Texture::draw(SDL_Renderer*& renderer) const
{ 
    SDL_Rect quad = { position.x, position.y, dimensions.w, dimensions.h };
    SDL_RenderCopy(renderer, texture, NULL, &quad);
}

void Texture::draw(SDL_Renderer*& renderer, const ns::Rect<int>& clipping) const
{ 
    SDL_Rect quad = { 
        position.x, 
        position.y, 
        clipping.w, 
        clipping.h 
    };

    SDL_RenderCopy(renderer, texture, &clipping, &quad);
}

void Texture::setPosition(ns::Coor2<int> newPosition)
{ 
    position = newPosition;
}

void Texture::setDimensions(ns::Dim2<int> newDimensions)
{ 
    dimensions = newDimensions;
}

void Texture::setColor(const ns::Color& color)
{
    SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

void Texture::setBlendMode(const SDL_BlendMode& blending)
{
    SDL_SetTextureBlendMode(texture, blending);
}

void Texture::setTransparency(const Uint8& alpha)
{
    SDL_SetTextureAlphaMod(texture, alpha);
}

ns::Coor2<int> Texture::getPosition() const
{ 
    return position;
}

ns::Dim2<int> Texture::getDimensions() const
{ 
    return dimensions;
}

void Texture::free()
{ 
    if (texture)
    {
        SDL_DestroyTexture(texture);

        texture = nullptr;
        dimensions.w = 0;
        dimensions.h = 0;
    }
}