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
#include "udpserver.hpp"

udpserver::udpserver()
{
	fp.create("transferredfile.txt");

}
	
void udpserver::m_saveToDisk()
{
	cout<<"writing file to disk"<<endl;
}

	
void udpserver::startListening(string ip, int port)
{
	/*Create UDP socket*/
	  udpsocket = socket(PF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in serverAddr;
	  /*Configure settings in address struct*/
	  serverAddr.sin_family = AF_INET;
	 serverAddr.sin_port = htons(port);
	 serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());
	 memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
	  /*Bind socket with address struct*/
	  bind(udpsocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
	addr_size = sizeof serverStorage;	
}

bool udpserver::waitForFileTransfer()
{
	cout<<"wait for file transer "<<endl;
	memset(buffer,0,sizeof(buffer));
	if( -1 != recvfrom(udpsocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size) )
	{
		cout<<"received "<<buffer<<endl;
		if(!strcmp(buffer,"start"))
		{
			cout<<"start received "<<endl;
			cout<<"ready to receive file data "<<endl;
			receiveFileData();
		}
	}
}

void udpserver::receiveFileData()
{
	cout<<"data is being received "<<endl;
	
	memset(buffer,0,sizeof(buffer));
	
	recvfrom(udpsocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);

	while(0 != strcmp(buffer,"stop"))
	{
		string s(buffer);
		fp.writeFile(s);

		memset(buffer,0,sizeof(buffer));
		recvfrom(udpsocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);
	}

	fp.closeWriteFile();
}	


