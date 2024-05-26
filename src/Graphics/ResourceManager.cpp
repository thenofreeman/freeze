#include "AssetManager.h"

namespace ns
{

ResourceManager* ResourceManager::Instance = nullptr;

ResourceManager::ResourceManager()
    : Instance{this}
{ }

ResourceManager::~ResourceManager()
{ }

ns::Texture& ResourceManager::loadTexture(std::string path)
{
    auto& textureMap = Instance->textures;

    ns::Texture& texture = textureMap[path];

    if (!texture)
        texture.load(path);

    return texture;
}

}