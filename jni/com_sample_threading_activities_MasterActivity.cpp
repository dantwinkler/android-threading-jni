#include "Globals.h"
#include "com_sample_threading_activities_MasterActivity.h"

/*
 * Class:     com_sample_threading_activities_MasterActivity
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_sample_threading_activities_MasterActivity_init( JNIEnv* env, jobject oMasterActivity )
{
	LOGI( "Java_com_sample_threading_activities_MasterActivity_init" );

	g_oMasterActivity = reinterpret_cast<jobject>( env->NewGlobalRef(
			oMasterActivity ) );

	jclass clazz = env->GetObjectClass( g_oMasterActivity );

	g_oLogMessageMethod = env->GetMethodID( clazz,
		"logMessage", "(Ljava/lang/String;)V" );
}

/*
 * Class:     com_sample_threading_activities_MasterActivity
 * Method:    startThread
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_sample_threading_activities_MasterActivity_startThread( JNIEnv* env, jobject )
{
	LOGI( "Java_com_sample_threading_activities_MasterActivity_startThread" );

	boost::recursive_mutex::scoped_lock( g_oMutex );

	if( g_oTaskRunner )
	{
		g_oTaskRunner.reset( );
	}
	else
	{
		g_oTaskRunner.reset( new TaskRunner( ) );
	}
}
