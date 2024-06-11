#include "Freeze/ShaderProgram.h"

namespace ns
{

ShaderProgram::ShaderProgram()
{ 
    programID = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{ }

void ShaderProgram::attachShader(ns::Shader* shader)
{ 
    glAttachShader(programID, shader->get());
    shaders.push_back(shader);
}

void ShaderProgram::attachShader(const ns::ShaderType& stype, const char* path)
{
    ns::Shader* shader = new ns::Shader(stype, path);

    glAttachShader(programID, shader->get());
    shaders.push_back(shader);
}

void ShaderProgram::link() const
{
    glLinkProgram(programID);

    int success;
    char infoLog[512];
    glGetProgramiv(programID, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(programID, 512, NULL, infoLog);
        std::cerr << "[ERROR] Shader Compilation Failed: " << infoLog << std::endl; 
    }
}

void ShaderProgram::deleteShaders()
{
    for (Shader* shader : shaders)
    {
        delete shader; 
        shader = nullptr;
    }
}


void ShaderProgram::use() const
{ 
    glUseProgram(programID);
}

void ShaderProgram::setUniform(const std::string& name, const bool& value) const
{ 
    glUniform1i(glGetUniformLocation(programID, name.c_str()), static_cast<int>(value));
}

void ShaderProgram::setUniform(const std::string& name, const int& value) const
{ 
    glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}

void ShaderProgram::setUniform(const std::string& name, const float& value) const
{ 
    glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}

}