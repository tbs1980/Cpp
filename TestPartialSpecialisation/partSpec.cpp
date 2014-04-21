#include<vector>

template<typename T,typename U>
class clintegrand
{
public:
	clintegrand(T x,U y)
	:m_x(x),m_y(y)
	{
	}
	
private:
	T m_x;
	U m_y;
};

template<class X> class calccl;


template<typename T,typename U>
class calccl<clintegrand<T,U> >
{
public:
	typedef clintegrand<T,U> clintegrandType;
	
	template<class vectorType>
	static void Generate(clintegrandType const &ci,vectorType const& vect)
	{
	}

};


int main(void)
{	
	typedef std::vector<double> vectorType;
	typedef clintegrand<double,int> clintType;
	typedef calccl<clintType> calcClPolicy;
	
	vectorType v(10,0);
	
	clintType clinte(10.,3);
	
	calcClPolicy::Generate(clinte,v);
	
}
