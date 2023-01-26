#include "vector.hpp"
#include <iostream>
#include <cctype>
#include "pair.hpp"
#include <utility>
#include <vector>

using std::cout;

int main()
{
	//ft::vector<int> test(1, 0);


	// for (uint16_t count = 0; count < 100 ; count++)
	//    test.push_back(count);
	// for (ft::vector<int>::iterator it = test.begin(); it < test.end(); it++)
	// 	cout << *it << " ";
	// cout << "\n";
	// test.erase(test.end());
	// for (ft::vector<int>::iterator it = test.begin(); it < test.end(); it++)
	// 	cout << *it << " ";
	// cout << "\n";
	ft::vector<int> sexo(1, 5);
	sexo.push_back(9);
	sexo.push_back(57);
	sexo.push_back(45);
	sexo.push_back(78);
	sexo.erase(sexo.end());
	//sexo.erase(sexo.begin() + 1, sexo.end() -1);
	for (ft::vector<int>::iterator it = sexo.begin(); it != sexo.end(); it++)
		cout << *it << "\n";
	return (0);
}