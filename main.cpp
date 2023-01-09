#include "vector.hpp"
#include <iostream>

using std::cout;

int main()
{
    ft::vector<int>(10, 5) test;

    ft::vector<int>::iterator it;
    it = test.begin();
    cout << *it;
    return (0);
}