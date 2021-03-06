#include "myGLFunctions.h"
#include <sstream>
#include "myLogger.h"

/**
 * Basic initializations for GL.
 */
void MyGLInits() {

    // White background
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    MyLOGI("OpenGL %s, GLSL %s", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

    // check if the device supports GLES 3 or GLES 2
    const char* versionStr = (const char*)glGetString(GL_VERSION);
    if (strstr(versionStr, "OpenGL ES 3.")) {
        MyLOGD("Device supports GLES 3");
    } else {
        MyLOGD("Device supports GLES 2");
    }

    CheckGLErrors("MyGLInits");
}

/**
 * Checks for OpenGL errors.
 */
void CheckGLErrors(std::string funcName){

    GLenum err = glGetError();
    if (err == GL_NO_ERROR) {
        return;
    } else {
        MyLOGF("[FAIL GL] %s", funcName.c_str());
    }

    switch(err) {

        case GL_INVALID_ENUM:
            MyLOGE("GL_INVALID_ENUM: GLenum argument out of range");
            break;

        case GL_INVALID_VALUE:
            MyLOGE("GL_INVALID_VALUE: numeric argument out of range");
            break;

        case GL_INVALID_OPERATION:
            MyLOGE("GL_INVALID_OPERATION: operation illegal in current state");
            break;

        case GL_INVALID_FRAMEBUFFER_OPERATION:
            MyLOGE("GL_INVALID_FRAMEBUFFER_OPERATION: framebuffer object is not complete");
            break;

        case GL_OUT_OF_MEMORY:
            MyLOGE( "GL_OUT_OF_MEMORY: not enough memory left to execute command");
            break;

        default:
            MyLOGE("unlisted error");
            break;
    }
}