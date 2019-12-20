#include <jni.h>
#include <string>
#include <aaudio/AAudio.h>
#include "logger.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL test_crash() {
    int x = 10;
    int y = x / 0;
    LOGD("crash %d", y);
    throw "你今天必须给我崩！";
}

jstring Java_com_ysy_andkdev_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */,
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

jint Java_com_ysy_andkdev_MainActivity_sumArrayFromJNI(JNIEnv *env, jobject /* this */, jintArray j_arr) {
    int *arr = env->GetIntArrayElements(j_arr, nullptr);
    if (arr == nullptr) {
        return 0;
    }
    int sum = 0;
    int len = env->GetArrayLength(j_arr);
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    env->ReleaseIntArrayElements(j_arr, arr, 0);
    return sum;
}

#ifdef __cplusplus
}
#endif

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    // test_crash();
    return JNI_VERSION_1_6;
}
