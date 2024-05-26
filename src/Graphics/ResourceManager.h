#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL_image.h>

#include "Texture.h"

namespace ns
{

class ResourceManager
{
    public:
        virtual ~ResourceManager()

        static ResourceManager& getInstance()
        {
            static AssetManager instance;
            return instance;
        }

        Texture* loadTexture(std::string path);

    public:

    private:
        std::vector<Texture*> textures;

    private:
        ResourceManager();

};

}