#include <cstdlib>
#include <iostream>

//http://en.wikipedia.org/wiki/Dangling_pointer

void Assign(int * integer)
{
	//you cannot allocate the memory here.
	//it has to be assigned first and then passed here.
	for(int i=0;i<10;++i)
	{
		integer[i] = i;
	}

	for(int i=0;i<10;++i)
	{
		std::cout<<"in the Assign \t"<<integer[i]<<std::endl;
	}
}


class TestAssign
{
public:
	TestAssign()
	:myint(NULL)
	{
		//so we need to allocate the memory here.
		myint=(int*)malloc(10*sizeof(int));
		Assign(myint);

		for(int i=0;i<10;++i)
		{
			std::cout<<"in the constructor \t"<<myint[i]<<std::endl;
		}
	}
	~TestAssign()
	{
		if(myint!=NULL) free(myint);
	}
private:
	int* myint;
};

int main(void)
{
	TestAssign test;

	return 0;
}

