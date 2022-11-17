#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>

typedef struct RENTri {
  float vertices[9];
  GLuint shaderProgram;
  GLuint VAO;
} RENTri;

typedef struct RENRect {
  float vertices[12];
  float indices[6];
  GLuint shaderProgram;
  GLuint VAO;
} RENRect;

extern GLuint renCompileVertexShader();
extern GLuint renCompileFragmentShader();
extern GLuint renCreateShaderProgram(GLuint, GLuint);
extern RENTri renInitTri(float[9]);
extern RENRect renInitRect(float[12], float[6]);
extern void renDrawTri(RENTri);
extern void renDrawRect(RENRect);