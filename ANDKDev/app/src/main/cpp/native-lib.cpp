#include <jni.h>
#include <string>
#include "logger.h"

#ifdef __cplusplus
extern "C" {
#endif

void test_crash() {
    int x = 10;
    int y = x / 0;
//    LOGD("crash %d", y);
}

jstring Java_com_ysy_andkdev_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */,
                                                        jint end_i, jstring str) {
    test_crash();

    long sum = 0;
    for (int i = 0; i < end_i; ++i) {
        printf("TEST-1 %d", i);
//        LOGD("%d", i);
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

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
//    test_crash();
    return JNI_VERSION_1_6;
}

#ifdef __cplusplus
}
#endif
