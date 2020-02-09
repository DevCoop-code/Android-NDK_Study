LOCAL_PATH := $(abspath $(call my-dir))

include $(CLEAR_VARS)
JNI_SRC_PATH := $(LOCAL_PATH)/../../cpp/

LOCAL_MODULE := hello-jni
LOCAL_SRC_FILES := $(JNI_SRC_PATH)/hello-jni.c
LOCAL_C_INCLUDES := $(JNI_SRC_PATH)

include $(BUILD_SHARED_LIBRARY)