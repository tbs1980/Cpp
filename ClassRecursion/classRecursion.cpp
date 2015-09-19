#include <vector>
#include <iostream>

template<typename realScalarType>
class myclass
{
public:
    myclass(std::vector<realScalarType> const & x)
    :pmc(nullptr),mX(x),mXInds(x.size())
    {
        long halfSize = x.size()/2;
        std::vector<realScalarType> halfX(halfSize);

        if(halfSize>4)
        {
            std::cout<<"halfSize = "<<halfSize<< " hence branching"<<std::endl;
            pmc = new myclass(halfX);
        }
        else
        {
            std::cout<<"halfSize = "<<halfSize<< " hence not branching"<<std::endl;
        }
    }

    ~myclass()
    {
        if(pmc != nullptr)
        {
            std::cout<<"**Deleting"<<std::endl;
            delete pmc;
        }
    }
private:
    myclass* pmc;
    std::vector<realScalarType> mX;
    std::vector<long> mXInds;
};

int main(void)
{
    std::vector<double> x(25,double(0));
    //myclass* pmc = new myclass(x);
    //delete pmc;

    myclass<double> mc(x);

    return 0;
}
