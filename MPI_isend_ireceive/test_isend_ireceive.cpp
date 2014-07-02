#include <boost/mpi.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>

int main(void)
{
	boost::mpi::environment env;
	boost::mpi::communicator world;
	
	
	std::vector<double> vect(world.size());
	
	srand(world.rank()+100);
	
	for(size_t i=0;i<world.size();++i)
	{
		if(i==world.rank())
		{
			vect[i]=(double)rand()/(double)RAND_MAX;
			std::cout<<"processor "<<i<<" rand= "<<vect[i]<<std::endl;
		}
	}
	
	world.barrier();
	
	if(world.rank()==0)
	{
		std::cout<<"\nThe vector in processor 0 has the following elements"<<std::endl;
	}
	
	for(size_t i=0;i<world.size();++i)
	{
		if(world.rank()==0)
			std::cout<<i<<"\t"<<vect[i]<<std::endl;
	}
	
	if(world.rank()==0)
	{
		std::cout<<"\ndistributing the elements"<<std::endl;
	}
	
	//receive values from other processors
	std::vector<boost::mpi::request> reqs2(world.size()-1);
	size_t rind=0;
	for(size_t source=0;source<world.size();++source)
	{		
		if(source==world.rank())
		{
			//send my value to others
			std::vector<boost::mpi::request> reqs1(world.size()-1);
			
			size_t sind=0;
			for(size_t dest=0;dest<world.size();++dest)
			{
				if(dest != world.rank())
				{
					reqs1[sind] = world.isend(dest,source,vect[source]);
					++sind;
				}
			}
			
			boost::mpi::wait_all(reqs1.begin(), reqs1.end());
		}
		else
		{
			//double x=0;
			
			reqs2[rind] =  world.irecv(source, source, vect[source]);
			++rind;
		}
	}
	
	boost::mpi::wait_all(reqs2.begin(), reqs2.end());	
	
	if(world.rank()==0)
	{
		std::cout<<"\nafter distributing the elements the values are \n"<<std::endl;
	}
	
	if(world.rank()==0)
	{
		for(size_t i=0;i<world.size();++i)
		{
			std::cout<<i<<"\t"<<vect[i]<<std::endl;
		}
	}
	
	return 0;
}
