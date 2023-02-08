#include <vector>
#include <iostream>

using std::cout;

int main()
{
	std::vector<int> test;

	for (int i = 0; i < 6; i++)
	{
		cout << i << "\n";
		test.push_back(i);
	}
	cout << "capacity is: " << test.capacity() << "\n";
	test[5] = 5;
	return (0);
}