#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Freeze/ShaderType.h"

namespace ns
{

class Shader
{
    public:
        Shader(const ns::ShaderType& stype, const char* path);
        virtual ~Shader();

        unsigned int get() const;

    private:
        unsigned int shader;
        unsigned int type;

};

}