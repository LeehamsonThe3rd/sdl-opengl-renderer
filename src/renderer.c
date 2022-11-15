#include <ren/renderer.h>

struct renTri {
    float vertices[6];
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int VBO, VAO;
};

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

static void renInitTriangle(REN_TRI *triangle) {

    triangle->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(triangle->vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(triangle->vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(triangle->vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(triangle->vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n %d\n", infoLog);
    }

    triangle->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(triangle->fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(triangle->fragmentShader);

    glGetShaderiv(triangle->fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(triangle->fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n %d\n", infoLog);
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, triangle->vertexShader);
    glAttachShader(shaderProgram, triangle->fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n %d\n", infoLog);
    }
    glDeleteShader(triangle->vertexShader);
    glDeleteShader(triangle->fragmentShader);

    glGenVertexArrays(1, &triangle->VAO);
    glGenBuffers(1, &triangle->VBO);

    glBindVertexArray(triangle->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, triangle->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle->vertices), triangle->vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0); 
}

static void renDrawTriangle(REN_TRI triangle) {
    
}

int main() {
    REN_TRI tri;
    renInitTriangle(&tri);
    renDrawTriangle(tri);
}