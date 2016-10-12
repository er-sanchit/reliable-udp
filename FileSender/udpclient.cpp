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
#include "udpclient.hpp"
using namespace std;

udpclient::udpclient(char* ip, int port)
{
	m_ip = ip;
	portnumber = port;		
	clientsocket = socket(PF_INET, SOCK_DGRAM, 0);
	
	/*Configure settings in address struct*/
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr(ip);
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
	/*Initialize size variable to be used later on*/
	addr_size = sizeof serverAddr;

}

void udpclient::sendStartMarker()
{
	cout<<"sending start marker "<<endl;
	string marker = "start";
	if( -1 != sendto(clientsocket,marker.c_str(),strlen(marker.c_str()),0,(struct sockaddr *)&serverAddr,addr_size))
	{
		cout<<"start marker sent"<<endl;
	}
	else
	{
		perror("error in sendto : ");
	}
}

void udpclient::sendFile(char* fileName)
{
	fileoperations fp(fileName);
	cout<<"Reading the File "<<endl;
	fp.readFile();
	cout<<"sending file "<<endl;
	char buff[20];
	memset(buff,0,sizeof(buff));
	while( 0 != fp.getNBytes(buff, 10) )
	{	cout<<buff<<endl;
		sendto(clientsocket,buff,10,0,(struct sockaddr *)&serverAddr,addr_size);
	}
	sendto(clientsocket,"stop",4,0,(struct sockaddr *)&serverAddr,addr_size);
}
	
int udpclient::send(char* buffer, int nBytes)
{
	sendto(clientsocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
	return 1;
}
	
