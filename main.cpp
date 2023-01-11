#include "vector.hpp"
#include <iostream>

using std::cout;

int main()
{
    ft::vector<int> test(10, 5);
    ft::vector<int>::iterator it;

    it = test.begin();
    cout << *it << "\n";
    return (0);
}