#include <jni.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_sean_gldemo_DateUtil_dateFromJNI(JNIEnv *env) {

    // Get a class reference for DateUtil class and get constructor method id
    jclass dateUtilClass = (env)->FindClass("com/sean/gldemo/DateUtil");
    jmethodID dateUtilConstructor = (env)->GetMethodID(dateUtilClass, "<init>", "()V");

    // Create DateUtil object and get non-static methodID of getFormattedDate()
    jobject dateUtilObject = (env)->NewObject(dateUtilClass, dateUtilConstructor);
    jmethodID dateMethodId = (env)->GetMethodID(dateUtilClass,"getFormattedDate","()Ljava/lang/String;");

    // Execute & return getFormattedDate method
    return (jstring) env->CallObjectMethod(dateUtilObject, dateMethodId);
}