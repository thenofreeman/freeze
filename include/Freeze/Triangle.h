#pragma once

#include <glad/glad.h>

#include <string>

#include "Freeze/ShaderProgram.h"

namespace ns
{

class Triangle
{
    public:
        Triangle();
        virtual ~Triangle();

        void draw() const;

    private:

};

}