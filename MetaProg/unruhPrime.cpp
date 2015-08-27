template<int p, int i>
class is_prime
{
public:
    enum{ prim = (p==2) ||  (p%i) && is_prime<(i>2?p:0),i-1>::prim   };
};

template<>
class is_prime<0,0>
{
public:
    enum {prim = 1 };
};

template<>
class is_prime<0,1>
{
public:
    enum {prim = 1 };
};

template<int i>
class D
{
public:
    D(void*);
};


// primary template for loop to print prime numbers
template<int i>
class Prime_print
{
public:
    Prime_print<i-1> a;
    enum{ prim = is_prime<i,i-1>::prim};
    void f()
    {
        D<i> d = prim? 1 : 0;
        a.f();
    }
};

// full specialisation to end the loop
template<>
class Prime_print<1>
{
public:
    enum {prim = 0};
    void f()
    {
        D<1> d = prim ? 1 : 0 ;
    }
};

#ifndef LAST
#define LAST 5
#endif

int main(void)
{
    Prime_print<LAST> a;
    return 0;
}
