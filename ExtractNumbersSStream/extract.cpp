#include <iostream>
#include <sstream>
#include <sstream>

//see http://www.cplusplus.com/reference/sstream/istringstream/istringstream/

int main(void)
{
	std::string stringvalues = "125 320 512 750 333";
	std::istringstream iss (stringvalues);
	
	while(!iss.eof())
	{
		int val;
		iss >> val ;
		std::cout << val*2 << '\n';
		
		//if(iss.eof()) break;
	}
	
	return 0;
}
