#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<double> x = {0.1, 0.2, 0.6, 0.4, 0.9, 0.3};

    auto result = std::minmax_element(
        x.begin(),
        x.end(),
        [](double a,double b)
        {
            return a < b; // puts min to first and max to second
            // return a < b; // puts min to second and max to first
        }
    );

    std::cout << "min element at: " << (result.first - x.begin()) << std::endl;
    std::cout << "max element at: " << (result.second - x.begin()) << std::endl;

}
