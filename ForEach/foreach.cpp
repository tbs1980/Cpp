#include <algorithm>
#include <vector>
#include <iostream>


void printNames(std::vector<std::string >& names)
{
    std::for_each(names.begin(), names.end(),
        [&](const std::string& name)
        {
            std::cout<<name<<std::endl;
        }
    );
}


int main(void)
{
    std::vector<std::string > names;

    names.push_back("name1");
    names.push_back("name2");
    names.push_back("name3");

    //std::for_each(names.begin(), names.end(), [](std::string &n){ std::cout<<n<<std::endl; });

    printNames(names);

    return 0;
}
