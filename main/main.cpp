#include "vector.hpp"
#include <iostream>
#include <cctype>
#include "pair.hpp"
#include <utility>
#include <vector>

using std::cout;

int main()
{
    // ft::vector<int> test(10, 5);
    // ft::vector<std::string> hola(10, "Hola!");

    // ft::vector<int>::iterator it = test.begin();
    // ft::vector<std::string>::iterator sit = hola.begin();
    // ft::vector<std::string> copy(hola.begin(), hola.end());
    // ft::vector<int>::iterator ot = test.end();

    // it = test.begin();
    // ft::vector<int> sexo(it, ot);
    // cout << *it << "\n";
    // ft::pair<int, int> def;
    // ft::pair<int, int> val(20, 30);
    // ft::pair<int, int> copy(val);

    // cout << "Default Test: " << "First Value->" << def.first << " Second Value->" << def.second << "\n";
    // cout << "Value Test: " << "First Value->" << val.first << " Second Value->" << val.second << "\n";
    // cout << "Copy Test: " << "First Value->" << copy.first << " Second Value->" << copy.second << "\n";
	std::vector<int> test(10, 14);
	std::vector<int>::reverse_iterator	r_it;
	// ft::reverse_iterator<ft::vector<int>::iterator> r_it;

	r_it = test.rbegin();
	cout << *r_it << "\n";
    return (0);
}