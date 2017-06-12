#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "myLogger.h"
#include "myGLFunctions.h"
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>

class Triangle {
public:
    Triangle();
    void    PerformGLInits();
    void    Render();
    void    SetViewport(int width, int height);
    bool    IsInitsDone(){return initsDone;}

private:
    void    RenderTriangle();
    void    AnimateTriangle();

    bool    initsDone;

    // vertex buffer for triangle's vertices, colors
    GLuint  vertexBuffer, colorBuffer;
    // will hold attributed for shader variables
    GLuint  vertexAttribute, colorAttribute;
    GLuint  shaderProgramID;

    float   triangleVertexDelta, triangleSwapRate;

};

#endif //TRIANGLE_H