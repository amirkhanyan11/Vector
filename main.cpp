#include <iostream>
#include "vector.hpp"
#include <vector>



int main()
{
    std::vector<int> svec = {5, 6, 7};

    juju::vector<int> vec = {1, 2, 3, 4};


    juju::vector<int>::const_iterator cit = vec.cbegin();

    cit++;

    for(juju::vector<int>::iterator it : vec)
    {
        // std::cout << it << std::endl;
    }
}