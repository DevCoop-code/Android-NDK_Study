#include <string.h>
#include <jni.h>

/*
See the more information below
https://developer.android.com/ndk/samples/sample_hellojni

JNIEnv* :Point to VM
jobject: this object from Java side
*/
JNIEXPORT jstring JNICALL
Java_com_hankyojeong_sampleapp_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz)
{
    #if defined(__arm__)
        #if defined(__ARM_ARCH_7A__)
            #if defined(__ARM_NEON__)
                #if defined(__ARM_PCS_VFP)
                    #define ABI "armeabi-v7a/NEON (hard-float)"
                #else
                    #define ABI "armeabi-v7a/NEON"
                #endif
            #else
                #if defined(__ARM_PCS_VFP)
                    #define ABI "armeabi-v7a (hard-float)"
                #else
                    #define ABI "armeabi-v7a"
                #endif
            #endif
        #else
            #define ABI "armeabi"
        #endif
    #elif defined(__i386__)
        #define ABI "x86"
    #elif defined(__x86_64__)
        #define ABI "x86_64"
    #elif defined(__mips64)
        #define ABI "mips64"
    #elif defined(__mips__)
        #define ABI "mips"
    #elif defined(__aarch64__)
        #define ABI "arm64-v8a"
    #else
        #define ABI "unknown"
    #endif

    return (*env)->NewStringUTF(env, "Hello from JNI ! compiled with ABI " ABI ".");
}