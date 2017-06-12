#include <jni.h>
#include "triangle.h"
#include "myJNIHelper.h"

#ifdef __cplusplus
extern "C" {
#endif

// global pointer is used in JNI calls to reference to same object of type Triangle
Triangle * gTriangleObject=NULL;

// global pointer to instance of MyJNIHelper that is used to read from assets
MyJNIHelper * gHelperObject=NULL;

/**
 * Create the persistent native object and also initialize the single helper object
 */
JNIEXPORT void JNICALL
Java_com_sean_gldemo_GLActivity_CreateObjectNative(JNIEnv *env,
                                                                             jobject instance,
                                                                             jobject assetManager,
                                                                             jstring pathToInternalDir) {

    gHelperObject = new MyJNIHelper(env, instance, assetManager, pathToInternalDir);
    gTriangleObject = new Triangle();
}

JNIEXPORT void JNICALL
Java_com_sean_gldemo_GLActivity_DeleteObjectNative(JNIEnv *env,
                                                                             jobject instance) {
    if (gTriangleObject != NULL) {
        delete gTriangleObject;
    }
    gTriangleObject = NULL;

    if (gHelperObject != NULL) {
        delete gHelperObject;
    }
    gHelperObject = NULL;
}

#ifdef __cplusplus
}
#endif