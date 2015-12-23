#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <iterator>

// g++ -std=c++11 accumulate.cpp

struct myContainer
{
    int mA;
    double mB;
};

int main(void)
{
    std::vector<myContainer> contVect(5);
        
    for(size_t i=0;i<contVect.size();++i)
    {
        contVect[i].mA = int(i);
        contVect[i].mB = 2.*double(contVect.size()-1 - i);
        std::cout<<contVect[i].mA<<"\t"<<contVect[i].mB<<std::endl;
    }
    
    int sumA = std::accumulate
    (
        std::begin(contVect),
        std::end(contVect),
        int(0),
        [](int & a,myContainer & b)
        {
            return a != int(0) ? a + b.mA  : b.mA ;
        }
    );
    
    std::cout<<"sum of As = "<<sumA<<std::endl;

    double sumB = std::accumulate
    (
        std::begin(contVect),
        std::end(contVect),
        double(0),
        [](double & a,myContainer & b)
        {
            return a != double(0) ? a + b.mB  : b.mB ;
        }
    );
    
    std::cout<<"sum of Bs = "<<sumB<<std::endl;
    
    return 0;
}
