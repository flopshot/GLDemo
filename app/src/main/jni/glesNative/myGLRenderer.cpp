#include <jni.h>
#include "triangle.h"


#ifdef __cplusplus
extern "C" {
#endif

extern Triangle *gTriangleObject;

JNIEXPORT void JNICALL
Java_com_sean_gldemo_MyGLRenderer_DrawFrameNative(JNIEnv *env,
                                                                      jobject instance) {

    if (gTriangleObject == NULL) {
        return;
    }
    gTriangleObject->Render();

}

JNIEXPORT void JNICALL
Java_com_sean_gldemo_MyGLRenderer_SurfaceCreatedNative(JNIEnv *env,
                                                                           jobject instance) {

    if (gTriangleObject == NULL) {
        return;
    }
    gTriangleObject->PerformGLInits();

}

JNIEXPORT void JNICALL
Java_com_sean_gldemo_MyGLRenderer_SurfaceChangedNative(JNIEnv *env,
                                                                           jobject instance,
                                                                           jint width,
                                                                           jint height) {

    if (gTriangleObject == NULL) {
        return;
    }
    gTriangleObject->SetViewport(width, height);

}

#ifdef __cplusplus
}
#endif