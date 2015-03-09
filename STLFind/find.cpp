#include <vector>
#include <iostream>
#include <algorithm>

int main(void)
{
    std::vector<size_t> myVect(10);
    
    for(size_t i=0;i<myVect.size();++i)
    {
        myVect[i] = i*2;
    }
    
    std::cout<<"input vector is "<<std::endl;
    for(size_t i=0;i<myVect.size();++i)
    {
        std::cout<<i<<"\t"<<myVect[i]<<std::endl;
    }
    
    size_t val = 10;
    std::vector<size_t>::iterator it;
    it = std::find(myVect.begin(), myVect.end(), val);
    std::cout<<val<<" found at position "<<(it-myVect.begin())<<std::endl;
    
    val = 50;
    it = std::find(myVect.begin(), myVect.end(), val);
    std::cout<<val<<" found at position "<<(it-myVect.begin())<<std::endl;

    val = 0;
    it = std::find(myVect.begin(), myVect.end(), val);
    std::cout<<val<<" found at position "<<(it-myVect.begin())<<std::endl;

    val = 18;
    it = std::find(myVect.begin(), myVect.end(), val);
    std::cout<<val<<" found at position "<<(it-myVect.begin())<<std::endl;
    
    return 0;
}
