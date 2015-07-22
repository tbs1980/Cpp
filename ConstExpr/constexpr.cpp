#include <iostream>

class AClass
{
public:
  //constexpr static const double testval = 1e-9;
  static constexpr const double testval = 1e-9;
  static constexpr const double testval_1 = 2e-9;

  AClass(){}

  void printval(void)
  {
    double x = testval;
    double y = testval_1;
    std::cout<<"testvals  = "<<x<<"\t"<<y<<std::endl;
    double minxy = std::min(x,y);
    std::cout<<"minval = "<<minxy<<std::endl;
  }
};

int main(void)
{
  AClass ac;
  ac.printval();
  return 0;
}
