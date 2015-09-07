#include <iostream>

class myClass
{
public:
	explicit myClass(double xx)
	:x(xx)
	{

	}

	double logLik(double y)
	{
		return x*y;
	}
private:
	double x;
};


template<typename modelType>
void logLik(double* cube,double* lnew,void* context)
{
	modelType* model = static_cast<modelType*>(context);
	*lnew = model->logLik( (*cube) );
}

int main(void)
{
	typedef myClass myClassType;
	myClassType mc(2);
	double p = 4;
	std::cout<<"First call "<<mc.logLik(p)<<std::endl;

	double llik=0;



	myClassType* p_mc = & mc;
	void* p_mcv = static_cast<void*>(p_mc);

	logLik<myClassType>(&p,&llik,p_mcv);

	std::cout<<"Second call "<<llik<<std::endl;

	return 0;
}

