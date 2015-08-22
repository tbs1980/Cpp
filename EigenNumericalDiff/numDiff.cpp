#include <cmath>
#include <iostream>
#include <unsupported/Eigen/NumericalDiff>

template<typename _Scalar>
class NormDistFunctor
{
public:
    typedef _Scalar Scalar;
    typedef Eigen::Matrix<Scalar,Eigen::Dynamic,1> InputType;
    typedef Eigen::Matrix<Scalar,Eigen::Dynamic,1> ValueType;
    typedef Eigen::Matrix<Scalar,Eigen::Dynamic,1> JacobianType;
    typedef typename InputType::Index Index;

    void operator()(InputType const & x, ValueType & fx) const
    {
        fx(0) = 0;
        for(Index i=0;i<x.rows();++i)
        {
            fx(0) -= x(i)*x(i);
        }

        fx(0) *= 0.5;
    }

    Index values() const
    {
        return Index(1);
    }

    static const Index InputsAtCompileTime = 0;
    static const Index ValuesAtCompileTime = 1;

    Index numDims() const
    {
        return 10;
    }

    void derivs(InputType const & x, JacobianType & dx)
    {
        return x;
    }

    /*
    ValueType values() const
    {
        ValueType fx(1);
        fx(0) = 0;
        return fx;
    }*/
};

int main(void)
{
    typedef NormDistFunctor<double> sineFunctorType;
    typedef Eigen::NumericalDiff<sineFunctorType>  numDiffType;
    typedef sineFunctorType::InputType InputType;
    typedef sineFunctorType::JacobianType JacobianType;
    typedef sineFunctorType::ValueType ValueType;

    sineFunctorType sf;
    numDiffType nd;

    InputType x = InputType::Random(sf.numDims());
    JacobianType dx(sf.numDims());

    //ValueType val;
    //val.resize(sf.values());

    nd.df(x,dx);

    //std::cout<<dx<<std::endl;

    return 0;
}
