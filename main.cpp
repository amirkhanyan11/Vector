#include <iostream>
#include "vector.hpp"
#include <vector>

int main()
{
    std::vector<int> svec = {1, 2, 3, 4};

    juju::vector<int> vec = {1, 2, 3, 4};

    vec.push_back(21);

    std::vector<int>::iterator it = svec.begin();

    juju::vector<int>::iterator juj = vec.begin();

    ++juj;

    std::cout << *(juj.m_ptr) << std::endl;
}