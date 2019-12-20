cmake_minimum_required(VERSION 3.4.1)

add_library(
        test_native
        SHARED
        test_native.cpp)

add_library(
        test_nn
        SHARED
        test_nn.cpp)

target_link_libraries(
        test_native
        test_nn
        android
        log)
