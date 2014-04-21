#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#include <cmath>

double round_half_up(double n)
{
  return floor(n + 0.5);
}

int main(void)
{
	//make a random vector
	const size_t ndim=10;
	
	std::vector<double> data(ndim);
	std::vector<int> data_i(ndim);
	
	for(size_t i=0;i<ndim;++i)
	{
		data[i]=rand()/(double)RAND_MAX;
		data[i]*=10;
		data_i[i]=(int)round_half_up(data[i]);
		
		std::cout<<i<<"\t"<<data_i[i]<<std::endl;
	}
	
	//now sort
	std::sort(data_i.begin(),data_i.end());

	std::cout<<"sorted values\n"<<std::endl;
	for(size_t i=0;i<ndim;++i)
	{
		std::cout<<i<<"\t"<<data_i[i]<<std::endl;
	}
	
	int val= 8;//round_half_up(10*rand()/(double)RAND_MAX);
	
	std::vector<int>::const_iterator it =std::lower_bound(data_i.begin(), data_i.end(), val);
	
	std::cout<<"nearest to "<<val<<" is "<< (*it) <<"at position "<<(it-data_i.begin())<<std::endl;
	
	std::cout<<"cumulative values\n"<<std::endl;
	for(size_t i=1;i<ndim;++i)
	{
		data_i[i]+=data_i[i-1];
		std::cout<<i<<"\t"<<data_i[i]<<std::endl;
	}
	
}
