#include "mutexLock.h"

namespace esw
{
	int mutexLock::lock()
	{
		int s = pthread_mutex_init(&mtx,nullptr);
		if ( s != 0)
		{
			cout<<"Failed to initialize the mutex"<<endl;
			return s;
		}
		s = pthread_mutex_lock(&mtx);
		if ( s != 0)
		{
			cout<<"Failed to lock the mutex"<<endl;
			return s;
		}
		return s;
	}

	int mutexLock::unlock()
	{
		int s = pthread_mutex_unlock(&mtx);
		if(s != 0)
		{
			cout<<"Failed to unlock the mutex"<<endl;
			return s;
		}	
		pthread_mutex_destroy(&mtx);
		return s;
	}

}
