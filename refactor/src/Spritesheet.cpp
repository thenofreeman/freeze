#include "SpriteSheet.h"

namespace ns
{

Spritesheet::Spritesheet(std::string path)
    : dimensions{0, 0},
      texture{nullptr}
{
    AssetManager& assetManager = AssetManager::getInstance();

    texture = assetManager.loadTexture(path);

    dimensions = texture->getDimensions();
}

Spritesheet::~Spritesheet()
{ 
    delete texture;
    texture = nullptr;
}

Vector2<int> Spritesheet::getDimensions() const
{ 
    return dimensions;
}

Sprite* Spritesheet::createSprite(const SDL_Rect& clipping) const
{
    Sprite* newSprite = new Sprite(texture, clipping);
    newSprite->setDimensions({ clipping.w, clipping.h });

    return newSprite;
}

void Spritesheet::setDimensions(Vector2<int> newDimensions)
{ 
    dimensions = newDimensions;
}

}