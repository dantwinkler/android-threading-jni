#include "Globals.h"
#include "com_sample_threading_activities_MasterActivity.h"

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
