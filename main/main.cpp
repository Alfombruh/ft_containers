#include "vector.hpp"
#include <iostream>
#include <cctype>
#include "pair.hpp"
#include <utility>
#include <vector>

using std::cout;

// #include <time.h>
// template <class T>
// ft::vector<T> create_vector(size_t amount)
// {
// 	ft::vector<T> temp(0,0);
// 	srand(time(NULL));
// 	cout << "creating a vector of random amount of numbers (max: " << amount << ")\n";
// 	int max = rand() % amount;
// 	for (int i = 0; i < max; i++)
// 		temp.push_back(rand() % (amount * 10));
// 	return (temp);
// }

void vector_information(ft::vector<int> &vec)
{
	cout << "||||||||||||||||||||VECTOR|||||||||||||||||||||||||\n";
	cout << "Vector size is:		" << vec.size() << "\n";
	cout << "Vector capacity is:	" << vec.capacity() << "\n";
	cout << "Vector contents are:		\n";
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
	cout << "\n";
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
}

void segfault(ft::vector<int>  vec)
{
	// cout << "segfault\n";
	// cout << "Vector size is:		" << vec.size() << "\n";
	// cout << "Vector capacity is:	" << vec.capacity() << "\n";
	// cout << "Vector contents are:		\n";
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
}

int main()
{
	try
	{
		ft::vector<int> vec(2, 5);

		segfault(vec);
		vector_information(vec);
		vec.push_back(24);
		vec.push_back(65);
		vec.push_back(809213);
		vector_information(vec);

	}
	catch(std::exception &e)
	{
		cout << e.what() << "\n";
	}
	return (0);
}