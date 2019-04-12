#include <jni.h>
#include <string>
#include "logger.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_ysy_andkdev_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */,
                                                jint end_i, jstring str) {
    long sum = 0;
    for (int i = 0; i < end_i; ++i) {
        printf("TEST-1 %d", i);
        LOGD("%d", i);
        sum += i;
    }

    const char *c_str = nullptr;
    c_str = env->GetStringUTFChars(str, nullptr);
    if (c_str == nullptr) {
        c_str = "123";
    }
    std::string hello = "Hello from C++ " + std::to_string(sum) + " " + c_str;
    env->ReleaseStringUTFChars(str, c_str);
    return env->NewStringUTF(hello.c_str());
}
