#include <Eigen/Core>
#include <iostream>
#include <fstream>

int main(void)
{
	typedef Eigen::MatrixXd MatrixXd;
	typedef MatrixXd::Index Index;
	//typedef MatrixXd::Scalar Scalar;
	
	const Index dim=3;
	
	MatrixXd x=MatrixXd::Random(dim,dim);
	
	std::ofstream of;
	of.open("eigen_matrix.dat",std::ios::trunc);
	
	Eigen::IOFormat csvFormat(Eigen::StreamPrecision,0,",","\n","","","","");
	
	//std::cout<<x.format(csvFormat)<<std::endl;
	
	of<<x.format(csvFormat);
	
	of.close();
	
	
	return 0;
}
