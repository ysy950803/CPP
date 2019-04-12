#include <jni.h>
#include <string>
#include "logger.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_ysy_andkdev_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    int sum = 0;
    for (int i = 0; i < 100; ++i) {
        printf("TEST-1 %d", i);
        LOGD("%d", i);
        sum += i;
    }
    std::string hello = "Hello from C++ " + std::to_string(sum);
    return env->NewStringUTF(hello.c_str());
}
