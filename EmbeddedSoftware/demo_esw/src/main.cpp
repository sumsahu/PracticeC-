#include<iostream>
#include "socket.h"
using namespace esw;

int main(int argc, char* argv[])
{
	const char PORT_NUM[]="50000";
    clientRequestHdlr clientReqHdlr;

	socketHandle *sock = socketHandle::getInstance();
	int sockFd=sock->listenSocket(PORT_NUM);
  
	if(sockFd == -1)
	{
		cout<<"Failed to create server socket"<<endl;
		exit(1);
	}
    //int sockFd = sock->getServerSocket();
	clientReqHdlr.start(sockFd);
	pthread_join(clientReqHdlr.getThreadId(),NULL);
	exit(EXIT_SUCCESS);
}

