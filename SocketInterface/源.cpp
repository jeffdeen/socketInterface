#include"URLConnection.h"
#include<iostream>
#include <cassert>

int main()
{
	char* url = "127.0.0.1";
	int port = 12345;
	URLConnection connection(url, port);
	connection.openConnection();
	char* src = new char[20];
	connection.getData(src);
	connection.sendData(src);
	std::cout << src << std::endl;
	connection.closeConnection();
}
