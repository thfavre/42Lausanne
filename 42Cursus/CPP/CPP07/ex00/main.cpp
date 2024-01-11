#include <iostream>
#include "swap.hpp"
#include "min.hpp"
#include "max.hpp"

int main()
{
	int a = 2;
	int b = 3;
	std::cout << a << " " << b << std::endl;
	swap<int>(a,b); // We can explicit
	std::cout << a << " " << b << std::endl;

	std::string c = "cccccc";
	std::string d = "dddddddd";
	std::cout << c << " " << d << std::endl;
	swap(c,d);
	std::cout << c << " " << d << std::endl;

	std::cout << std::endl;

	std::cout << max(1, 4) << std::endl;
	std::cout << max(2, 1) << std::endl;

	std::cout << std::endl;

	std::cout << min(1, 4) << std::endl;
	std::cout << min(2, 1) << std::endl;
	std::cout << min(-1122, 1) << std::endl;


}
