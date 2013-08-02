#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <strings.h>
#include <android/log.h>
#include <jni.h>
#include "TaskRunner.h"
#include <boost/thread/recursive_mutex.hpp>


//////////////////////////////////////////////////////////
// Global Object Definitions
//////////////////////////////////////////////////////////

extern JavaVM*					g_pJavaVM;

extern boost::recursive_mutex 	g_oMutex;

extern TaskRunnerPtr 			g_oTaskRunner;

//////////////////////////////////////////////////////////
// Global Function Definitions
//////////////////////////////////////////////////////////

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, "libnav", __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , "libnav", __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , "libnav", __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , "libnav", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , "libnav", __VA_ARGS__)

#endif
