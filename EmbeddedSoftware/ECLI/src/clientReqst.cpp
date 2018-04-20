#include "clientReqst.h"
using namespace esw;

int main(int argc, char* argv[])
{
	const char port[] = "50000";
	const int BUF_SIZE = 100;
	socketHandle *sock = socketHandle::getInstance();
	int connFd = sock->connectSocket(port);
	if(connFd == -1)
	{
		cout<<"Failed to create the client socket"<<endl;
		exit(1);
	}	
	char buf[BUF_SIZE];
		
	ssize_t numRead;
	//Reading data from standard input
	while((numRead=read(STDIN_FILENO,buf,BUF_SIZE)) > 0)
	{
		if(write(connFd,buf,numRead) != numRead)
			cout<<"Partial Write"<<endl;
	}	
	if(numRead == -1)
		cout<<"Fatal Error"<<endl;

	while((numRead=read(connFd,buf,BUF_SIZE)) > 0)
	{
		if(write(STDOUT_FILENO,buf,numRead) != numRead)
			cout<<"Partial write to console"<<endl;
	}
	if(close(connFd) == -1)
	{
		cout<<"Failed to close the client fd"<<endl;
	}

	exit(0);
}
