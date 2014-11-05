#include <iostream>
#include <vector>

//http://stackoverflow.com/questions/19062733/what-is-the-motivation-behind-static-polymorphism-in-c

template<class Derived>
class Base
{
public:
    void interface()
    {
        static_cast<Derived*>(this)->implementation();
    }
};

class Derived1 : public Base<Derived1>
{
public:
    void implementation()
    {
        std::cout<<"Derived1"<<std::endl;
    }
};

/*
class Derived2 : Base<Derived2>
{
public:
    void implementation()
    {
        std::cout<<"Derived2"<<std::endl;
    }
};
*/

int main(void)
{
    Base<Derived1> bd1;
    //Base<Derived2> bd2;

    bd1.interface();
    //bd2.interface();

    return 0;
}
