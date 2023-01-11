#include <vector>
#include <iostream>

using std::cout;

int main()
{
	// std::vector<int> sexo;
	// for (int i = 0; i < 20; i++)
	// 	sexo.push_back(i * 20);
	// std::vector<int>::iterator it = sexo.begin();
	// std::vector<int>::iterator ot = sexo.end() - 1;
	// std::vector<int>::iterator result;

	// cout << "it b4 changes " << *it << "\n";
	// cout << "ot b4 changes " << *ot << "\n\n";
	// it - ot;
	// cout << "it after changes" << *it << "\n";
	// cout << "ot after changes" << *ot << "\n";
	//cout << "result is: " << *result << "\n";
	std::integral_constant< bool , 50> hola;

	cout << hola << "\n";

	return (0);
}