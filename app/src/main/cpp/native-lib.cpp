#include <jni.h>
#include <string>
#include "TestLock.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_sensetime_testucproblem_MainActivity_init(
        JNIEnv* env,
        jobject /* this */) {

    TestLock::getInstance().initReveiver();

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_sensetime_testucproblem_MainActivity_ping(
        JNIEnv* env,
        jobject /* this */) {


    TestLock::getInstance().testWaitLock();

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_sensetime_testucproblem_MainActivity_notifyThread(
        JNIEnv* env,
        jobject /* this */) {


    TestLock::getInstance().notify();

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}