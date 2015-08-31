#include <cmath>
#include <iostream>
#include <unsupported/Eigen/NumericalDiff>

template<typename _Scalar, int NX=Eigen::Dynamic, int NY=Eigen::Dynamic>
class NormDistFunctor
{
public:
    typedef _Scalar Scalar;
    enum
    {
        InputsAtCompileTime = NX,
        ValuesAtCompileTime = NY
    };

    typedef Eigen::Matrix<Scalar,InputsAtCompileTime,1> InputType;
    typedef Eigen::Matrix<Scalar,ValuesAtCompileTime,1> ValueType;
    typedef Eigen::Matrix<Scalar,ValuesAtCompileTime,InputsAtCompileTime> JacobianType;
    typedef typename InputType::Index Index;

    int m_inputs, m_values;

    NormDistFunctor()
    : m_inputs(InputsAtCompileTime), m_values(ValuesAtCompileTime)
    {

    }

    NormDistFunctor(int inputs, int values)
    : m_inputs(inputs), m_values(values)
    {

    }

    int inputs() const
    {
        return m_inputs;
    }

    int values() const
    {
        return m_values;
    }

    void operator()(InputType const & x, ValueType & fx) const
    {
        fx(0,0) = 0;
        for(Index i=0;i<x.rows();++i)
        {
            fx(0,0) -= x(i)*x(i);
        }

        fx(0,0) *= 0.5;
    }

    void derivs(InputType const & x, JacobianType & dx)
    {
        dx = -x.transpose();
    }

};

int main(void)
{
    typedef NormDistFunctor<double,Eigen::Dynamic,1> sineFunctorType;
    typedef Eigen::NumericalDiff<sineFunctorType>  numDiffType;
    typedef sineFunctorType::InputType InputType;
    typedef sineFunctorType::JacobianType JacobianType;
    typedef sineFunctorType::ValueType ValueType;


    const int numDims = 10;

    sineFunctorType sf;
    numDiffType nd(sf);

    InputType x = InputType::Random(numDims);
    JacobianType dx(1,numDims);

    nd.df(x,dx);

    std::cout<<dx<<std::endl;

    JacobianType dxExpected(1,numDims);
    sf.derivs(x,dxExpected);

    std::cout<<dxExpected<<std::endl;

    return 0;
}
