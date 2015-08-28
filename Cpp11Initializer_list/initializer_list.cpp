#include <iostream>
#include <vector>

// http://www.bogotobogo.com/cplusplus/C11/C11_initializer_list.php
// g++ -std=c++11 -pedantic -Wall ./initializer_list.cpp
class MyClass
{
public:
    MyClass(std::initializer_list<int> const & v)
    {
        for(auto itm : v)
        {
            mVec.push_back(itm);
        }
    }

    void print()
    {
        for(auto itm : mVec)
        {
            std::cout << itm << " ";
        }
        std::cout<<std::endl;
    }

private:
    std::vector<int> mVec;
};

int main()
{
    MyClass m = {1,2,3,4};
    m.print();

    // another example
    std::vector<int> v = {1, 2, 3, 4};

    return 0;
}
