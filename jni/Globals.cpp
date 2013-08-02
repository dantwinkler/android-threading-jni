#include "Globals.h"
#include <boost/thread/tss.hpp>

//////////////////////////////////////////////////////////
// Global Object Definitions
//////////////////////////////////////////////////////////

JavaVM*					g_pJavaVM = 0;

jobject					g_oMasterActivity = NULL;

jmethodID				g_oLogMessageMethod = NULL;

boost::recursive_mutex	g_oMutex;

TaskRunnerPtr			g_oTaskRunner;

//////////////////////////////////////////////////////////
// Global Function Definitions
//////////////////////////////////////////////////////////

class ThreadJNIEnv
{

private:

	bool		m_bDetach;

	JNIEnv*		m_pJavaEnv;

public:

	ThreadJNIEnv( ) :
		m_pJavaEnv( NULL )
	{
		LOGI( "Attaching Thread" );

		g_pJavaVM->AttachCurrentThread( &m_pJavaEnv, NULL );

		m_bDetach = true;
	}

	ThreadJNIEnv( JNIEnv* pJavaEnv ) :
		m_pJavaEnv( pJavaEnv )
	{
		LOGI( "Attach (main thread): %p ", m_pJavaEnv );
	}

	~ThreadJNIEnv( )
	{
		if( m_bDetach )
		{
			LOGI( "Detaching Thread" );

			g_pJavaVM->DetachCurrentThread( );

			sleep( 1 );
		}
	}

	JNIEnv* GetEnv( ) { return m_pJavaEnv; };
};

// Class which manages JNIEnv per thread
boost::thread_specific_ptr<ThreadJNIEnv> g_oJNIEnv;

JNIEnv* GetJNIEnv( )
{
	// Do we already have a JNIEnv?
	ThreadJNIEnv* pJNIEnv = g_oJNIEnv.get( );

	if( pJNIEnv == NULL )
	{
		// Create a new JNIEnv (attach the thread)
		g_oJNIEnv.reset( new ThreadJNIEnv( ) );
	}

	return g_oJNIEnv->GetEnv( );
}

jint JNI_OnLoad( JavaVM* vm, void* reserved )
{
	g_pJavaVM = vm;
//
//	JNIEnv* pJniEnv = NULL;
//	g_pJavaVM->GetEnv( (void **)&pJniEnv, JNI_VERSION_1_6 );
//
//	// Add the main thread environment
//	g_oJNIEnv.reset( new ThreadJNIEnv( pJniEnv ) );

	LOGI( "JNI_OnLoad called: vm=%p, env=%p", g_pJavaVM, NULL );

	return JNI_VERSION_1_6;
}
