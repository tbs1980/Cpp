#include <iostream>

template<int N>
class pow3
{
public:
    enum{result = 3*pow3<N-1>::result };
};

template<>
class pow3<0>
{
public:
    enum{result = 1};
};

int main(void)
{
    std::cout<<"pow3<4>::result = "<<pow3<4>::result<<std::endl;
    return 0;
}
