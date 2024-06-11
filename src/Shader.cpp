#include "Freeze/Shader.h"

namespace ns
{

Shader::Shader(const ns::ShaderType& stype, const char* path)
    : type{static_cast<unsigned int>(stype)}
{ 
    // assert ShaderType matches path extension

    std::string scode;
    std::ifstream file;

    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        file.open(path);

        std::stringstream stream;

        stream << file.rdbuf();

        file.close();

        scode = stream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cerr << "[ERROR]: Shader file not successfully read." << std::endl;
    }

    const char* code = scode.c_str();

    shader = glCreateShader(type);
    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "[ERROR] Shader Compilation Failed: " << infoLog << std::endl; 
    }
}

Shader::~Shader()
{ 
    glDeleteShader(shader);
}

unsigned int Shader::get() const
{
    return shader;
}

}