#include "URLConnection.h"
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll
URLConnection::URLConnection(char* url, int port)
{
	//初始化DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//创建套接字
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//向服务器发起请求
	memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = inet_addr(url);
	sockAddr.sin_port = htons(port);
}

URLConnection::~URLConnection()
{
}

int URLConnection::openConnection()
{
	//success:1 ; fail:0
	if (connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR)) != SOCKET_ERROR)
		return 1;
	return 0;
}

int URLConnection::sendData(char* src)
{
	//success 1 ; fail 0
	if (send(sock, src, strlen(src) + sizeof(char), NULL) != SOCKET_ERROR)
		return 1;
	return 0;
}

int URLConnection::getData(char* src)
{
	if (recv(sock, src, strlen(src) + sizeof(char), NULL)!=SOCKET_ERROR)
		return 1;
	return 0;
}

int URLConnection::closeConnection()
{
	//关闭套接字
	if (closesocket(sock) != SOCKET_ERROR)
	{
		//终止使用 DLL
		WSACleanup();
		return 1;
	}
	WSACleanup();
	return 0;
	
}
