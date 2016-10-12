#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
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
#include <iostream>
#include <fstream>
#include "fileoperations.hpp"
using namespace std;



class udpclient
{
	int clientsocket, portnumber;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	string m_ip;
	socklen_t addr_size;

	public:
		udpclient(char* ip, int port);
		void sendStartMarker();
		void sendFile(char* fileName);	
		int send(char* buffer, int nBytes);	
	
};
