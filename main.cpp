#include <iostream>
#include "vector.h"
#include <vector>



int main()  
{
    juju::vector<int> vec = {1, 2, 3};

    //juju::vector<int>::iterator i = vec.begin();


    for (auto i : vec)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

