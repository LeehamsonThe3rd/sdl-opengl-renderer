#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>

typedef struct RENTri {
  //float vertices[9];
  GLuint shaderProgram;
  GLuint VAO;
} RENTri;

typedef struct RENRect {
  //float vertices[12];
  //float indices[6];
  GLuint shaderProgram;
  GLuint VAO;
} RENRect;

extern GLuint renCompileVertexShader();
extern GLuint renCompileFragmentShader();
extern GLuint renCreateShaderProgram(GLuint, GLuint);
extern RENTri renInitTri();
extern RENRect renInitRect();
extern void renDrawTri(RENTri);
extern void renDrawRect(RENRect);