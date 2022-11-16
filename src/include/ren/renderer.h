#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>

typedef struct RENTri {
  float vertices[6];
  GLuint shaderProgram;
  GLuint VAO;
} RENTri;

extern GLuint renCompileVertexShader();
extern GLuint renCompileFragmentShader();
extern GLuint renCreateShaderProgram(GLuint, GLuint);
extern RENTri renInitTriangle(float[6]);
extern void renDrawTriangle(RENTri);