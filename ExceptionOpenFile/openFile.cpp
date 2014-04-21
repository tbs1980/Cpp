#include <fstream>
#include <string>
#include <iostream>


//To check if an exception is thrown when 
//a non-existing file is opened.

int main(void)
{
	std::ifstream infile;
	std::string filename("testfile.txt");
	
	try
	{
		infile.open(filename.c_str(),std::ios::in);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
