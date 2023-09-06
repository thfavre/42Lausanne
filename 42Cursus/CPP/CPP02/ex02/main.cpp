#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	// std::cout << std::endl << "----- Constructor Time! -----" << std::endl << std::endl;

	Fixed	a;
	Fixed const	b( Fixed(5.05f) * Fixed(2));

	std::cout << std::endl << "----- Values -----" << std::endl << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << std::endl << "----- max & min -----" << std::endl << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	// std::cout << std::endl << "----- Destructor Time! -----" << std::endl << std::endl;

	return (0);
}
