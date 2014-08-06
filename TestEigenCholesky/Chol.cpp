#include <iostream>
#include <cassert>
#include <Eigen/Core>
#include <Eigen/Dense>

int main(void)
{
	Eigen::MatrixXd A(3,3);
	A << 4,-1,2, -1,6,0, 2,0,5;
	std::cout << "The matrix A is" << std::endl << A << std::endl;
	Eigen::LLT<Eigen::MatrixXd> lltOfA(A); // compute the Cholesky decomposition of A
	Eigen::MatrixXd L = lltOfA.matrixL(); // retrieve factor L  in the decomposition
	std::cout << "The Cholesky factor L is" << std::endl << L << std::endl;
	
	Eigen::VectorXd v=Eigen::VectorXd::Random(3);
	
	std::cout<<"v= "<<v<<std::endl;
	
	std::cout<<"L*v= "<<L*v<<std::endl;
	
	std::cout<<"\n--------------------\n"<<std::endl;
	
	Eigen::MatrixXd B(2,2);
	B << 4,0, 0,0;
	std::cout << "The matrix A is" << std::endl << A << std::endl;
	Eigen::LDLT<Eigen::MatrixXd> ldltOfB(B); // compute the Cholesky decomposition of A
	std::cout<<"ldltOfB.info() ="<<ldltOfB.info()<<std::endl;
	assert(ldltOfB.info()==Eigen::Success);
	Eigen::MatrixXd Lb = ldltOfB.matrixL(); // retrieve factor L  in the decomposition
	std::cout << "The Cholesky factor L is" << std::endl << Lb << std::endl;
	std::cout<< "\nThe diagonal matrix D is "<<ldltOfB.vectorD ()<<std::endl;
	
	return 0;
}
