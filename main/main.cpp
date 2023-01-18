#include "vector.hpp"
#include <iostream>
#include <cctype>
#include "pair.hpp"
#include <utility>
#include <vector>

using std::cout;

int main()
{
    ft::vector<char> sexo(10, 'c');
    sexo.clear();
    for (unsigned long ul = 0; ul < 10; ul++)
        cout << sexo.at(ul) << "\n";
    return (0);
}