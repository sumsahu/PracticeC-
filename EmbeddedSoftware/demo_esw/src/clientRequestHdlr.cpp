#include "clientRequestHdlr.h"

namespace esw
{

	int clientRequestHdlr::start(int sockFd)
	{
		cout<<"sockFd = = "<<sockFd<<endl;
		int rval = pthread_create(&requestThreadHdlr,NULL,clientRequestHdlr::run,(void*)&sockFd);
		if(rval != 0)
		{
			cout<<"Failed to start the request Handler Thread"<<endl;
		}	
		pthread_exit(NULL);
	}
	pthread_t clientRequestHdlr::getThreadId()
	{
		return requestThreadHdlr;
	}
    void* clientRequestHdlr::run(void* arg)
    {
        int serverFd = *((int*)arg);
		cout<<"serverFd received "<<serverFd<<endl;

		socketHandle *sockObj= socketHandle::getInstance();
		if(sockObj == nullptr)
		{
			cout<<"Failed to get the instance of socket handle"<<endl;
			exit(1);
		}
	
    	clientFd = sockObj->acceptRequest(serverFd);
		if(clientFd == -1)
		{
			cout<<"Failed to get the client request"<<endl;
			exit(1);
		}
		ssize_t numRead;
		const int bufsize = 100;
		char buf[bufsize];
		if((numRead = read(clientFd,buf,bufsize)) > 0)
		{
			if(write(STDOUT_FILENO,buf,numRead) != numRead)
			{
				cout<<"Partial Write"<<endl;
			}
		}
		if(numRead == -1)
		{
			cout<<"Fatal Error"<<endl;
		}
		strcpy(buf,"Message received\n");
		if(write(clientFd,buf,strlen(buf)) != (unsigned int)strlen(buf))
		{
			cout<<"Partial write"<<endl;
		}
		if(close(clientFd) == -1)
			cout<<"Failed to close the connection FD"<<endl;
		pthread_exit(NULL);
    }
	int clientRequestHdlr::clientFd=0;

}
