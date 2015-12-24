#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{

	std::vector<double> v(10);

	for(size_t i=0;i<v.size();++i)
	{
		v[i] =  i;
		std::cout<<i<<"\t"<<v[i]<<std::endl;
	}


	std::vector<double>::iterator low;

	double val=-1;
	low = std::lower_bound (v.begin(), v.end(), val);
	std::cout<<"val= "<<val<<" position of lower_bound = "<<low-v.begin()<<std::endl;

	val=0;
	low = std::lower_bound (v.begin(), v.end(), val);
	std::cout<<"val= "<<val<<" position of lower_bound = "<<low-v.begin()<<std::endl;

	val=5.1;
	low = std::lower_bound (v.begin(), v.end(), val);
	std::cout<<"val= "<<val<<" position of lower_bound = "<<low-v.begin()<<std::endl;

	val=5.5;
	low = std::lower_bound (v.begin(), v.end(), val);
	std::cout<<"val= "<<val<<" position of lower_bound = "<<low-v.begin()<<std::endl;

	val=9.9;
	low = std::lower_bound (v.begin(), v.end(), val);
	std::cout<<"val= "<<val<<" position of lower_bound = "<<low-v.begin()<<std::endl;

	val=10;
	low = std::lower_bound (v.begin(), v.end(), val);
	std::cout<<"val= "<<val<<" position of lower_bound = "<<low-v.begin()<<std::endl;

	val=12;
	low = std::lower_bound (v.begin(), v.end(), val);
	std::cout<<"val= "<<val<<" position of lower_bound = "<<low-v.begin()<<std::endl;

	return 0;
}

