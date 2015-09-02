#include <boost/math/special_functions/expint.hpp>

int main(void)
{
    double xMin = std::log10(1e-3);
    double xMax = std::log10(1e1);
    double numSteps = 1000;
    double dx = (xMax - xMin)/numSteps;
    for(int i=0;i<numSteps;++i)
    {
        double xi = std::exp(xMin+i*dx);
        std::cout<<xi<<"\t"<<boost::math::expint(xi)<<std::endl;
    }
    return 0;
}
