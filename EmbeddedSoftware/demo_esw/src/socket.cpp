#include "socket.h"
namespace esw
{
     socketHandle* socketHandle::getInstance()
     {
         if(sockObj == nullptr)
         {
             mutexLock lockMtx;
             lockMtx.lock();
             if(sockObj == nullptr)
             {
                 sockObj = new socketHandle();
             }
             lockMtx.unlock();
         }
         return sockObj;
     }

     int socketHandle::listenSocket(const char port[])
     {
         int sockFd;
         struct addrinfo hints;
         struct addrinfo *result,*rp;
         //Set the memory to 0
         memset(&hints,0, sizeof(struct addrinfo));
         //get the possible list of address that can be used to bind the address
         hints.ai_canonname = NULL;
         hints.ai_addr = NULL;
         hints.ai_next = NULL;
         hints.ai_socktype = SOCK_STREAM;
         hints.ai_family = AF_UNSPEC;
         hints.ai_flags = AI_NUMERICSERV | AI_PASSIVE;
         if(getaddrinfo(NULL,port,&hints,&result) == -1) 
         {
             cout<<"Failed to get the possible address info"<<endl;
             return -1; 
         }
         for(rp = result;rp != NULL;rp = rp->ai_next)
         {
             sockFd = socket(rp->ai_family,rp->ai_socktype,rp->ai_protocol);
             if(sockFd == -1) 
             {
                 cout<<"Failed to create the socket. continue with the other address"<<endl;
                 continue;
             }
			 //servSocket->_fd = sockFd;
			 //strcpy(servSocket->port,port);
			 //listOfServerSocket = sockFd;
             if(bind(sockFd,rp->ai_addr,rp->ai_addrlen) == 0)
                 break;
             if(close(sockFd) == -1) 
                 cout<<"Failed to close the fd"<<endl;
         }
    
         if(rp == NULL)
         {
             cout<<"Failed to get the possible address list"<<endl;
             return -1; 
         }

         freeaddrinfo(rp);

         if(listen(sockFd,BACKLOG) == -1)
         {
             close(sockFd);
             cout<<"Failed to listen to the socket"<<endl;
             return -1;
         }
		 
		 return sockFd;
     }

	
     int socketHandle::connectSocket(const char port[],char hostname[])
     {
         int connFd;
         struct addrinfo hints;
         struct addrinfo *result,*rp;
         //Set the memory to 0
         memset(&hints,0, sizeof(struct addrinfo));
         //get the possible list of address that can be used to bind the address
         hints.ai_canonname = NULL;
         hints.ai_addr = NULL;
         hints.ai_next = NULL;
         hints.ai_socktype = SOCK_STREAM;
         hints.ai_family = AF_UNSPEC;
         hints.ai_flags = AI_NUMERICSERV | AI_PASSIVE;
         if(getaddrinfo(hostname,port,&hints,&result) == -1) 
         {
             cout<<"Failed to get the possible address info"<<endl;
             return -1; 
         }
         for(rp = result;rp != NULL;rp = rp->ai_next)
         {
             connFd = socket(rp->ai_family,rp->ai_socktype,rp->ai_protocol);
             if(connFd == -1) 
             {
                 cout<<"Failed to create the socket. continue with the other address"<<endl;
                 continue;
             }
             if(connect(connFd,rp->ai_addr,rp->ai_addrlen) == 0)
                 break;
             if(close(connFd) == -1) 
                 cout<<"Failed to close the fd"<<endl;
         }
    
         if(rp == NULL)
         {
             cout<<"Failed to get the possible address list"<<endl;
             return -1; 
         }

         freeaddrinfo(rp);
		 return connFd; 
     }
	 int socketHandle::acceptRequest(const int sockfd)
	 {
		int connFd;
		cout<<"sockFd = "<<sockfd<<endl;
		while(1)
		{
		connFd = accept(sockfd,NULL,NULL);
		break;
		if(connFd  == -1)
		{
			cout<<"Failed to accept the incoming socket request"<<endl;
			continue;
		}
		break;
		}
		return connFd;
	
	 }
	 int socketHandle::getServerSocket()
	 {
		/*
		
	     list<int>::iterator it = listOfServerSocket.begin();
		 for(;it != listOfServerSocket.end();it++)
		 {
		     return *it;
		 }
		 //return listOfServerSocket;*/
		 return 0;
	 }
	 socketHandle* socketHandle::sockObj = nullptr;

}
