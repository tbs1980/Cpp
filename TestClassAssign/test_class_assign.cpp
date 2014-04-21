#include <iostream>

class A
{
public:
	A()
	{
	
	}
	
	A(size_t N1,size_t N2)
	:m_N1(N1),m_N2(N2)
	{
	
	}
	
	~A()
	{
		std::cout<<"destroy!"<<std::endl;
	}
	
	void Print()
	{
		std::cout<<"N1= "<<m_N1<<"\t N2="<<m_N2<<std::endl;
	}
private:
	size_t m_N1;
	size_t m_N2;
};

int main(void)
{
	A mya1(1,2);
	A mya2;
	
	mya2=mya1;
	
	mya2.Print();
	
	return 0;
}
