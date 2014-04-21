#include<iostream>
#include<vector>

template<typename T,typename V>
class TestClass
{
public:
	static T GetValue(T x,V const& g)
	{
		return g*x;
	}	
};


template<typename T,typename R>
class TestClass<T,std::vector<R> >
{
public:
	static T GetValue(T x,std::vector<R> const& g)
	{
		T val=0;
		for(unsigned i=0;i<g.size();++i)
		{
			val+=(T)g[i];
		}
		return val*x;
	}
};

int main(void)
{
	TestClass<double,int> mytest;
	
	std::cout<<"result normal="<<mytest.GetValue(10,20)<<std::endl;
	
	std::vector<double> vect(5,10);
	
	TestClass<double,std::vector<double> > myTestSpecial;
	
	std::cout<<"result special="<<myTestSpecial.GetValue(10,vect)<<std::endl;
	
	return 0;
}
