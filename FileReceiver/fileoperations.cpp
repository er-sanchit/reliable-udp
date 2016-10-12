#include "fileoperations.hpp"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

fileoperations::fileoperations()
{

}

fileoperations::fileoperations(char* name):fname(name),buffer(5000),filePointer(0)
{
	inputFile.open(name, ios::in);
}

fileoperations::~fileoperations()
{

}

void fileoperations::readFile()
{
	char*  buff  = new char[10000];
	inputFile.seekg(0, std::ios::end);	
	std::streamsize size = inputFile.tellg();
	std::cout<<"size of a file is "<<size<<endl;
	inputFile.seekg(0, std::ios::beg);
	buffer.reserve(size);
	inputFile.read(buffer.data(), size);
	cout<<"File is being read "<<endl;
}

void fileoperations::printFile()
{
	std::cout<<buffer.data()<<endl;
	
}

char* fileoperations::getNBytes(char* buff, int numBytes)
{
	
	strncpy(buff,&buffer[filePointer],numBytes);
	*(buff+numBytes+1) = '\0'; 
	filePointer += numBytes;
	return buff;
}

unsigned int fileoperations::m_getfileSize()
{
	
}

void fileoperations::writeFile(string s)
{	
	cout<<"\nwrite file "<<endl;
	outputFile<< s;
}

void fileoperations::closeReadFile()
{
	inputFile.close();
}

void fileoperations::closeWriteFile()
{
	outputFile.close();
}

void fileoperations::create(char* str)
{
	outputFile.open(str, ios::out | ios::app);
}
