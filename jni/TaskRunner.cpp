#include "Globals.h"

#include "TaskRunner.h"

TaskRunner::TaskRunner( ) :
	m_oThread( )
{
	m_oThread.reset( new boost::thread( boost::bind( &TaskRunner::OnRun, this ) ) );

	m_oThread->join( );
}

TaskRunner::~TaskRunner( )
{
}

void TaskRunner::OnRun( )
{
	LOGI( "Thread Started" );

	LOGI( "Thread Ended" );
}
