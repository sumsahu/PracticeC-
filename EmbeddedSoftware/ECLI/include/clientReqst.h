#ifndef _CLIENT_REQST_H_
#define _CLIENT_REQST_H_
#include "socket.h"
#include "clientRequestHdlr.h"


namespace esw
{
	class clientReqst
	{
		private:
			int clientFd;
		public:
			clientReqst()
			{
				clientFd = -1;
			}	
			~clientReqst(){}

	};
}
#endif
