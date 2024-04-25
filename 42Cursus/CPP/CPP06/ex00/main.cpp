#include <iostream>

#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		std::cout << "Usage: ./convert [string]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
