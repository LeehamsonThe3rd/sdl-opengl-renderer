#include <ren/renderer.h>

struct renTri {
    float vertices[6];
    GLuint VBO, VAO;
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

static GLuint renCompileVertexShader() {
    GLuint vertexShader;
    glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
        printf(infoLog);
        return;
    }
  
    return vertexShader;
}

static GLuint renCompileFragmentShader() {
    GLuint fragmentShader
  
    glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    int success;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);             
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
        printf(infoLog);
        return;
    }
  
    return vertexShader;
}

static GLuint renMakeShaderProgram(GLuint vertexShader, GLuint fragmentShader) {
    GLuint shaderProgram
  
    glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
        return;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

static void renInitTriangle(REN_TRI *triangle) {

    GLuint vertexShader = renCompileVertexShader();
    GLuint fragmentShader = renCompileFragmentShader();
    GLuint shaderProgram = renMakeShaderProgram();

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