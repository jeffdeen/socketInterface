// Jeff Deen
// 2017 03 16 22:17
#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#include <WinSock2.h>

class URLConnection
{
public:
	explicit URLConnection(char* url,int port);
	~URLConnection();
	int openConnection();
	int sendData(char* src);
	int getData(char* src);
	int closeConnection();
private:
	SOCKET sock;
	sockaddr_in sockAddr;
};
