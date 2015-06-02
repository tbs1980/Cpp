#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

int main(void)
{
    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
    return 0;
}
