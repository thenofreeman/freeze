#include "Freeze/Triangle.h"

namespace ns
{

Triangle::Triangle()
{
    ShaderProgram shaderProgram;
    shaderProgram.attachShader(ShaderType::VERTEX, "../shaders/shader.vs");
    shaderProgram.attachShader(ShaderType::FRAGMENT, "../shaders/shader.fs");
    shaderProgram.deleteShaders();
    shaderProgram.link();

    float vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // shader loop stuff (rest probably shouldn't be here)
    shaderProgram.use();
    glBindVertexArray(VAO);
}

Triangle::~Triangle()
{}

void Triangle::draw() const
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

}