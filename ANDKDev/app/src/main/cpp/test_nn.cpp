#include <jni.h>
#include <string>
#include <android/NeuralNetworks.h>
#include "logger.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL test_nn() {
    uint32_t *numDevices = nullptr;
    int res = ANeuralNetworks_getDeviceCount(numDevices);
    LOGD("res: %d", res);
}

#ifdef __cplusplus
}
#endif

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    test_nn();
    return JNI_VERSION_1_6;
}
