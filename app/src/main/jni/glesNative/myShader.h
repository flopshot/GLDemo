#ifndef MY_SHADER_H
#define MY_SHADER_H
#include "myGLFunctions.h"
#include "myLogger.h"

#include <string>

GLuint LoadShaders(std::string vertexShaderCode, std::string fragmentShaderCode);
GLuint GetAttributeLocation(GLuint programID, std::string variableName);

#endif //MY_SHADER_H