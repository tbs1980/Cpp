#include <cstdlib>
#include <cstdio>

void myFunc(unsigned int const N,double const * y,double *x)
{
    for(unsigned int i=0;i<N;++i)
    {
        x[i] = y[i]*y[i];
    }
}

int main(void)
{
    unsigned int const N=10;
    double* x = (double*)malloc(sizeof(double)*N);
    double* y = (double*)malloc(sizeof(double)*N);
    
    for(unsigned int i=0;i<N;++i)
    {
        y[i] = (double) i;
    }
    
    myFunc(N,y,x);
    
    for(unsigned int i=0;i<N;++i)
    {
        printf("%d\t%e\t%e\n",i,y[i],x[i]);
    }
    
    free(x);
    free(y);
}
