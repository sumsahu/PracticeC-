#ifndef _MUTEX_LOCK_H_
#define _MUTEX_LOCK_H_
#include<iostream>
using namespace std;
#include<pthread.h>
namespace esw
{
class mutexLock
{
	private:
		pthread_mutex_t mtx;
	public:
		int lock();
		int unlock();
};
}
#endif
