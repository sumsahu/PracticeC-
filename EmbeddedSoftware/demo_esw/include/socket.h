#ifndef _SOCKET_HANDLE_H_
#define _SOCKET_HANDLE_H_
#include<iostream>
#include<netdb.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
using namespace std;
#include<list>
#include "mutexLock.h"
#include "clientRequestHdlr.h"
#define BACKLOG 50
namespace esw
{
	struct socketData
	{
		int _fd;
		 char port[];
	};
	class socketHandle
	{
		private:
			socketHandle()
			{
			}
			socketHandle(socketHandle&);
			socketHandle& operator =(socketHandle&);
			~socketHandle(){}
			static socketHandle* sockObj;
		public:
			static socketHandle* getInstance();
			int listenSocket(const char port[]);			
			int connectSocket(const char port[],char hostname[]="localhost");
			int acceptRequest(const int sockfd);
			int getServerSocket();
	};			

}//namespace 
#endif
