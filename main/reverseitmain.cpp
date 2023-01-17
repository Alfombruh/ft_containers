#include "vector.hpp"
#include "reverse_iterator.hpp"
#include "iterator"

#include <iostream>

using std::cout;

int main()
{
	ft::vector<int> test(10, 14);
	ft::vector<int>::reverse_iterator	r_it;
	// ft::reverse_iterator<ft::vector<int>::iterator> r_it;

	r_it = test.rbegin();
	++r_it;
	cout << *r_it << "\n";
	return (0);
}