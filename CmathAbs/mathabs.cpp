#include <cmath>
#include <iostream>

// g++ -std=c++98 -pedantic -Wall mathabs.cpp

template<typename realScalarType>
realScalarType testAbs(realScalarType const & x)
{
    using std::abs;

    return abs(x);
}

int main(void)
{
    float x(2.9);
    double y(-4.5);
    long double z(-1e9);

    std::cout<<testAbs(x)<<"\t"<<testAbs(y)<<"\t"<<testAbs(z)<<std::endl;
}
