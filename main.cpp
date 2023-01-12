#include "vector.hpp"
#include <iostream>
#include <cctype>

using std::cout;

int main()
{
    ft::vector<int> test(10, 5);
    ft::vector<std::string> hola(10, "Hola!");

    ft::vector<int>::iterator it = test.begin();
    ft::vector<std::string>::iterator sit = hola.begin();
    ft::vector<std::string> copy(hola.begin(), hola.end());
    ft::vector<int>::iterator ot = test.end();

    it = test.begin();
    ft::vector<int> sexo(it, ot);
    cout << *it << "\n";
    return (0);
}