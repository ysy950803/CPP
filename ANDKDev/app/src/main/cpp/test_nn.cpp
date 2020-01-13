#include <jni.h>
#include <string>
#include <android/NeuralNetworks.h>
#include "logger.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL test_nn() {
    uint32_t numDevices = 0;
    int ret = ANeuralNetworks_getDeviceCount(&numDevices);
    LOGI("getDeviceCount %d %d", ret, numDevices);

    for (uint32_t i = 0; i < numDevices; i++) {
        ANeuralNetworksDevice *device = nullptr;
        ret = ANeuralNetworks_getDevice(i, &device);
        LOGI("getDevice %d", ret);

        const char *name = nullptr;
        ret = ANeuralNetworksDevice_getName(device, &name);
        LOGI("getName %d %s", ret, name);

        int32_t type = 0;
        ret = ANeuralNetworksDevice_getType(device, &type);
        LOGI("getType %d %d", ret, type);

        const char *version = nullptr;
        ret = ANeuralNetworksDevice_getVersion(device, &version);
        LOGI("getVersion %d %s", ret, version);

        int64_t featureLevel = 0;
        ret = ANeuralNetworksDevice_getFeatureLevel(device, &featureLevel);
        LOGI("getFeatureLevel %d %lld", ret, featureLevel);
    }
}

#ifdef __cplusplus
}
#endif

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    test_nn();
    return JNI_VERSION_1_6;
}
