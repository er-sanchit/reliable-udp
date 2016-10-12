#include <iostream>
#include <typeinfo>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "fileoperations.hpp"
using namespace std;

class udpserver
{
	int udpsocket;
	socklen_t addr_size;
	char buffer[1024];
	struct sockaddr_storage serverStorage;
	void m_saveToDisk();
	fileoperations fp;
	public:
	udpserver();	
	void startListening(string ip, int port);
	bool waitForFileTransfer();
	void receiveFileData();	




};
