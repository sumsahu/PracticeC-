#ifndef _CLIENT_REQUEST_HDLR_H_
#define _CLIENT_REQUEST_HDLR_H_
#include<iostream>
#include"socket.h"
namespace esw
{
class clientRequestHdlr
{
	private:
		pthread_t requestThreadHdlr;
		static int clientFd;
	public:
		clientRequestHdlr()
		{
			clientFd=0;
		}
		~clientRequestHdlr(){}
		static void* run(void* arg);
		int start(int sockFd);
		pthread_t getThreadId();
};
}
#endif
