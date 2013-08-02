#ifndef _TASK_RUNNER_
#define _TASK_RUNNER_

#include <boost/thread/recursive_mutex.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

typedef boost::function<void (bool)> ThreadCallback;

class TaskRunner
{

private:

	boost::shared_ptr<boost::thread>	m_oThread;

public:

	TaskRunner( );
	virtual ~TaskRunner( );

private:

	void OnRun( );

};

typedef boost::shared_ptr<TaskRunner> TaskRunnerPtr;

#endif // _TASK_RUNNER_
