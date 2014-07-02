#include <boost/mpi.hpp>
#include <boost/serialization/vector.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <Eigen/Core>

int main(void)
{
	boost::mpi::environment env;
	boost::mpi::communicator world;	
	
	Eigen::VectorXd vect=Eigen::VectorXd::Random(10);
	
	size_t source=0;

	if(world.rank()==source)
	{
		std::cout<<"\nassiging values to vector using processor 0\n"<<std::endl;
		for(size_t i=0;i<vect.size();++i)
		{
			//vect[i]=(double)rand()/(double)RAND_MAX;
			std::cout<<i<<"\t"<<vect(i)<<std::endl;
		}
	}
	
	return 0;
	
	world.barrier();
	
	if(world.rank()==source)
	{
		std::cout<<"\ncopying the vector to other processors\n"<<std::endl;
	}
	
	world.barrier();
	
	if(world.rank() == source)
	{
		std::vector<boost::mpi::request> reqs1(world.size()-1);
		for(size_t dest=0;dest<world.size();++dest)
		{
			size_t dind=0;
			if(dest != source)
			{
				reqs1[dind] = world.isend(dest,source,&vect(0,0),vect.size());
				++dind;
			}
		}
		
		boost::mpi::wait_all(reqs1.begin(), reqs1.end());
	}
	else
	{
		std::vector<boost::mpi::request> reqs2(world.size()-1);
		size_t rind = world.rank() > source ? world.rank()-1 : world.rank();
		reqs2[rind ] =  world.irecv(source, source, &vect(0,0),vect.size());
		
		boost::mpi::wait_all(reqs2.begin(), reqs2.end());
	}
	
	if(world.rank()==source)
	{
		std::cout<<"\nAfter copying the vector the vector in the last processor is\n"<<std::endl;
	}
	
	world.barrier();
	
	if(world.rank()==world.size()-1)
	{
		for(size_t i=0;i<vect.size();++i)
		{
			std::cout<<i<<"\t"<<vect(i)<<std::endl;
		}
	}
	//*/

	return 0;
}
