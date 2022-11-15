#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>

typedef struct renTri {
  float vertices[6];
  GLuint vertexShader;
  GLuint fragmentShader;
  GLuint VBO, VAO;
} REN_TRI;

extern GLuint renCompileVertexShader();
extern GLuint renCompileFragmentShader();
extern GLuint renCreateShaderProgram();
extern renTri renInitTriangle();
extern void renDrawTriangle();