#include <vector>
#include <iostream>
#include "vector.hpp"

#include <time.h>


using std::cout;

template <class T>
ft::vector<T> create_vector(size_t amount)
{
	ft::vector<T> temp(0,0);
	srand(time(NULL));
	cout << "creating a vector of random amount of numbers (max: " << amount << ")\n";
	int max = rand() % amount;
	for (int i = 0; i < max; i++)
		temp.push_back(rand() % (amount * 10));
	return (temp);
}

int main()
{
	ft::vector<int> test;
	ft::vector<int> limite;

	srand(time(NULL));
	cout << "creating a vector of random amount of numbers (max: 100)\n";
	int max = rand() % 20;
	for (int i = 0; i < max; i++)
		test.push_back(rand() % 100);
	max = rand() % 20;
	for (int i = 0; i < max; i++)
		limite.push_back(rand() % 100);
	cout << "Vector is: ";
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		cout << *it << ", ";
	cout << "\n";
	cout << "since vector begin to vector end:\n";
	for (std::vector<int>::iterator it = limite.begin() + 2; it != limite.end() - 3; it++)
		cout << *it << ",";
	cout << "\n";
	limite.assign(limite.begin(), limite.begin() + 1);
	cout << "Vector after assing: ";
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		cout << *it << ", ";
	cout << "\n";

	// ft::vector<int> test(20, 10);
	// test = create_vector<int>(20);

	// cout << "capacity before erase: " << test.capacity() << "\n";
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);
	// // test.erase(test.begin() + 6);

	// cout << "capacity after erase: " << test.capacity() << "\n";
	return (0);
}