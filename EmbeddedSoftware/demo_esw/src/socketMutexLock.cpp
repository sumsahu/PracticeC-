#include "socketMutexLock.h"
namespace esw
{
     int socketMutexLock::lock()
	 {
         int s = pthread_mutex_lock(&mtx);
         if(s != 0)
         {
             cout<<"Failed to lock the socketMutex"<<endl;
             return s;
         }
         return s;
     }
     int socketMutexLock::unlock()
     {
         int s = pthread_mutex_unlock(&mtx);
         if(s != 0)
         {
             cout<<"Failed to unlock the socketMutex"<<endl;
             return s;
         }
         return s;
     }
     socketMutexLock* socketMutexLock::getInstance()
     {
         if(sockMtx == nullptr)
         {
             mutexLock mtxLock;
             int retVal = mtxLock.lock();
             if(retVal != 0)
             {
                 cout<<"Failed to get the instance of mutexLock"<<endl;
                 return nullptr;
             }
             if(sockMtx == nullptr)
             {
                 sockMtx = new socketMutexLock();
             }
             retVal = mtxLock.unlock();
             if(retVal != 0)
             {
                 return nullptr;
            }
        }
        return sockMtx;
    }

	socketMutexLock* socketMutexLock::sockMtx = nullptr;
}
