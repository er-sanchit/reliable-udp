#include <fstream>
#include <string>
#include <vector> 

class fileoperations
{

public :

	fileoperations(char* fname );
	~fileoperations();

	void readFile(); 
	int  getNBytes(char* buff, int numBytes);
	void wrieFile();
	void create(char* str);
	void printFile();
	unsigned int m_getfileSize();
	void writeFile(std::string s);
	void closeWriteFile();
	void closeReadFile();	

private :
	std::ofstream outputFile;
	std::ifstream inputFile;	
	std::vector<char> buffer;
	std::string fname;
	int filePointer;
	int size;	
};
