#include "vector.hpp"
#include <iostream>
#include <cctype>
#include "pair.hpp"
#include <utility>
#include <vector>

using std::cout;

int main()
{
    ft::vector<int> test(1, 1);


    test.push_back(2);
    cout << "size is:   " << test.size() << " and capacity is: " << test.capacity() << "\n";
    cout << "at 2 is: " << test.at(1) << "\n";
    test.push_back(3);
    cout << "size is:   " << test.size() << " and capacity is: " << test.capacity() << "\n";
    cout << "at 3 is: " << test.at(2) << "\n";
    return (0);
}