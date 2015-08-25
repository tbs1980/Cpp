#include <iostream>

template<typename T>
struct maximum
{
    T operator()(const T &lhs, const T &rhs) const  {return (lhs > rhs) ? lhs:rhs;}
};

int main(void)
{
    int a = 1;
    int b = 2;

    std::cout<<"max is "<<maximum<long>()(a,b);

    return 0;
}
