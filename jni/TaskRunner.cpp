#include "Globals.h"

#include "TaskRunner.h"

TaskRunner::TaskRunner( ) :
	m_oMutex( ),
	m_oIOService( ),
	m_oWork( m_oIOService ),
	m_oDeadlineTimer( m_oIOService, boost::posix_time::seconds( 1 ) ),
	m_oThread( ),
	m_dwValue( 0 )
{
	Wait( );

	m_oThread.reset( new boost::thread( boost::bind( &TaskRunner::OnRun, this ) ) );
}

TaskRunner::~TaskRunner( )
{
	m_oIOService.stop( );

	try
	{
		m_oThread->join( );
	}
	catch( ... )
	{
		m_oThread->interrupt( );

		m_oThread->join( );

		throw;
	}
}

void TaskRunner::OnRun( )
{
	LOGI( "Thread Started" );

	m_oIOService.run( );

	LOGI( "Thread Ended" );
}

void TaskRunner::OnTimer( const boost::system::error_code& error )
{
	if( !error )
	{
		LOGI( "OnTimer: %d", m_dwValue );

		char pszMessage[1024] = { '\0' };
		sprintf( pszMessage, "The value is %d\n", m_dwValue );

		JNIEnv* pJNIEnv = GetJNIEnv( );

		jstring strPortJava = pJNIEnv->NewStringUTF( pszMessage );

		pJNIEnv->CallVoidMethod( g_oMasterActivity, g_oLogMessageMethod,
			strPortJava );

		m_dwValue++;

		m_oDeadlineTimer.expires_at( m_oDeadlineTimer.expires_at( ) + boost::posix_time::seconds( 1 ) );

		Wait( );
	}
	else
	{
		LOGI( "OnTimer error!" );
	}
}

void TaskRunner::Wait( )
{
	m_oDeadlineTimer.async_wait( boost::bind( &TaskRunner::OnTimer, this,
        boost::asio::placeholders::error ) );
}

