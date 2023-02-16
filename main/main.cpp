#include "rbt.hpp"
#include "pair.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::string;


int main()
{
	int key = 1;
	int key2 = 1512;
	string value = "sexo";
	string value2 = "sexo";
	RBT<int, string> nuevo;
	nuevo.insertNode((key + 1), (value + " sexo2"));
	nuevo.insertNode((key + 2), (value + " sexo3"));
	nuevo.insertNode((key + 3), (value + " sexo4"));
	nuevo.insertNode((key + 4), (value + " sexo5"));
	nuevo.insertNode((key + 5), (value + " sexo6"));
	nuevo.insertNode((key + 8), (value + " sexo8"));
	nuevo.insertNode((key + 7), (value + " sexo7"));
	nuevo.insertNode((key + 9), (value + " sexo9"));
	nuevo.printAing();
	return (0);
}