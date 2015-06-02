#include <iostream>

#include <Eigen/Core>

int main(void)
{

  //define the complex vector type
  typedef double realScalarType;
  typedef Eigen::Matrix<realScalarType,Eigen::Dynamic,1> realVectorType;
  typedef std::complex<realScalarType> complexScalarType;
  typedef Eigen::Matrix<complexScalarType,Eigen::Dynamic,1> complexVectorType;
  //typedef Eigen::Map<realVectorType> realVectorMapType;
  typedef Eigen::Map<complexVectorType>  complexVectorMapType;

  // create a real vector
  const size_t numDims = 10;
  realVectorType rVect(numDims);

  // assign values
  for(size_t i=0;i<numDims;++i)
  {
    rVect(i) = (realScalarType) i;
  }

  std::cout<<rVect<<std::endl;

  // convert this into a complex vector

  // get a pointer to the real vector data
  realScalarType* pR = rVect.data();

  // convert to a complex pointer
  complexScalarType* pC = reinterpret_cast<complexScalarType*>(pR);

  // map the data
  complexVectorMapType cMap(pC,numDims/2);

  std::cout<<"\n"<<cMap<<std::endl;

  return 0;
}
