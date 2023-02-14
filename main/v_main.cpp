#include "vector.hpp"
#include "stack.hpp"
#include <iostream>
#include <cctype>
#include "pair.hpp"
#include <utility>
#include <vector>
#include <stack>

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

void vector_compare()
{
	cout << "||||||||||||||||||||||||||||||||||||||||||||PACO_COMPARE||||||||||||||||||||||||||||||||||||||||||||\n";
	ft::vector<int> one(2, 5);
	ft::vector<int> sec(2, 5);

	cout << "Just made two equal vectors, the two with 2 numbers and those numbers are 5\n";
	if (one == sec)
		cout << "This prints if one == sec\n";
	one.push_back(25);
	one.push_back(25);
	one.push_back(25);
	sec.push_back(25);
	sec.push_back(25);
	sec.push_back(25);
	cout << "Just pushed 3 25's to the two vectors, they are still equal\n";
	if (one == sec)
		cout << "This prints if they are still equal\n";
	one.push_back(3);
	one.push_back(33);
	one.push_back(333);
	sec.push_back(4);
	sec.push_back(44);
	sec.push_back(444);
	cout << "Now pushed 3 33 333 into the first vecto and 4 44 444 into the second one\n";
	if  (one != sec)
		cout << "This shows if the vectors are not equal\n";
	one.clear();
	sec.clear();
	one.push_back(3);
	one.push_back(33);
	one.push_back(333);
	sec.push_back(3);
	sec.push_back(33);
	sec.push_back(333);
	sec.push_back(3333);
	cout << "Pushed 3 33 333 into the first vector and 3 33 333 3333 into the second one\n";
	if (one != sec)
		cout << "They are not equal\n";

	//TODO < > <= >= algunoo mas
}

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

void	vector_insert()
{
	ft::vector<int> test;

	for (size_t i = 0; i != 5; i++)
		test.push_back(i);
	vector_information(test);
	
	cout << *test.insert(test.begin() + 3, 20, 4);
	vector_information(test);
	std::vector<int> test2;

	for (size_t i = 0; i != 5; i++)
		test2.push_back(i);
	//vector_information(test2);
	
	cout << *test2.insert(test2.begin() + 3, 20, 4);
	//vector_information(test2);
}

int main()
{
	ft::stack<int> test;

	return (1);
	try
	{
		ft::vector<int> vec(2, 5);

		//segfault(vec);
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