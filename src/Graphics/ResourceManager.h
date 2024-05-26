#pragma once

#include <string>
#include <map>

#include "Texture.h"

namespace ns
{

class ResourceManager
{
    public:
        virtual ~ResourceManager();

        static ns::Texture& loadTexture(std::string path);

    public:

    private:
        std::map<std::string, ns::Texture> textures;

        static ResourceManager* Instance;

    private:
        ResourceManager();

};

}