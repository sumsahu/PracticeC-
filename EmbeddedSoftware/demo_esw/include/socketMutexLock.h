#ifndef _SOCKET_MUTEX_LOCK_H_
#define _SOCKET_MUTEX_LOCK_H_

#include<iostream>
#include "mutexLock.h"
#include <pthread.h>
using namespace std;
namespace esw
{
class socketMutexLock 
{
	private:
		pthread_mutex_t mtx;
		static socketMutexLock* sockMtx;

		socketMutexLock()
		{
			pthread_mutex_init(&mtx,nullptr);
		}
		socketMutexLock(socketMutexLock&);
		socketMutexLock& operator =(socketMutexLock&);
		~socketMutexLock(){
			pthread_mutex_destroy(&mtx);
		};
	public:
		int lock();
		int unlock();
		socketMutexLock* getInstance();
};

}//End of namespace 
#endif
