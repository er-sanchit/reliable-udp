#include <iostream>
#include "udpserver.hpp"
#include<cstring>

using namespace std;
int main()
{
//	fileoperations* handle = new fileoperations("../testfile.txt");
//	handle->readFile();
//	handle->printFile();
//	char* buff = new char[15];
//	memset(buff,'\0',sizeof(buff));
//	handle->getNBytes(buff, 15);	
//	cout<<"\nbuff is "<<buff<<endl;
//	printf("buff is : %s ",buff);
//	handle->getNBytes(buff,15);
//	cout<<" next buff is "<<buff<<endl;
//	handle->create("sanme.txt");
//	handle->writeFile("This is a test file");
//	handle->writeFile("This is second");
//	handle->closeWriteFile();
//
	udpserver server;
	server.startListening("127.0.0.1",7891);
	server.waitForFileTransfer();	
	return 0;
}
