# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

# Generate JNI Stubs from java classes (run from the jni directory)
# javah -classpath ../bin/classes com.sample.threading.MasterActivity

include $(CLEAR_VARS)
LOCAL_MODULE    := threadingjnilib
LOCAL_CFLAGS 	:= -D_GLIBCXX_DEBUG

FILE_LIST += $(wildcard $(LOCAL_PATH)/*.cpp)

LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_CFLAGS += -I$(LOCAL_PATH)/boost/include

LOCAL_LDLIBS := -llog -lEGL -lGLESv1_CM -lGLESv2

# Link with boost libraries
LOCAL_LDLIBS += $(LOCAL_PATH)/boost/lib/libboost_date_time-gcc-mt-1_53.a
LOCAL_LDLIBS += $(LOCAL_PATH)/boost/lib/libboost_system-gcc-mt-1_53.a
LOCAL_LDLIBS += $(LOCAL_PATH)/boost/lib/libboost_thread-gcc-mt-1_53.a

# Link with c++ libraries
LOCAL_LDLIBS += $(NDKROOT)/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi/libsupc++.a
LOCAL_LDLIBS += $(NDKROOT)/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi/libgnustl_static.a

# Library that lets your application code detect the target device's CPU family and the optional features at runtime.
LOCAL_STATIC_LIBRARIES := cpufeatures

include $(BUILD_SHARED_LIBRARY)
