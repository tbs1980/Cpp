#include <iostream>
#include <thread>

void hello()
{
	std::cout<<"Hello World\n"<<std::endl;
}

int main(void)
{
	std::thread t(hello);
	t.join();
}
