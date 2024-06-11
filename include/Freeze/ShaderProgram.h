#pragma once

#include <string>
#include <vector>

#include <glad/glad.h>

#include "Freeze/Shader.h"

namespace ns
{

class ShaderProgram
{
    public:
        ShaderProgram();
        virtual ~ShaderProgram();

        void attachShader(ns::Shader* shader);
        void attachShader(const ns::ShaderType& stype, const char* path);
        void link() const;
        void deleteShaders();
        void use() const;

        void setUniform(const std::string& name, const bool& value) const;
        void setUniform(const std::string& name, const int& value) const;
        void setUniform(const std::string& name, const float& value) const;

    private:
        unsigned int programID;
        std::vector<ns::Shader*> shaders;

};
    
}