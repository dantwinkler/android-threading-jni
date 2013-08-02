#ifndef _TASK_RUNNER_
#define _TASK_RUNNER_

#include <boost/thread/recursive_mutex.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

class TaskRunner
{

private:

	boost::recursive_mutex				m_oMutex;

	boost::asio::io_service				m_oIOService;

	boost::asio::io_service::work		m_oWork;

	boost::asio::deadline_timer			m_oDeadlineTimer;

	boost::shared_ptr<boost::thread>	m_oThread;

	int									m_dwValue;

public:

	TaskRunner( );
	virtual ~TaskRunner( );

private:

	void OnRun( );

	void OnTimer( const boost::system::error_code& error );

	void Wait( );

};

typedef boost::shared_ptr<TaskRunner> TaskRunnerPtr;

#endif // _TASK_RUNNER_
