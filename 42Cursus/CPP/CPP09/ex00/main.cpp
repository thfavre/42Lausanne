#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{

	std::cout << "laadasd\n" << std::endl;
	std::cout << argv[0] << std::endl;
	if (argc != 2)
	{
		std::cerr << "Use : ./head input_file" << std::endl;
		return (1);
	}
	BitcoinExchange btcE = BitcoinExchange(argv[1]);
}
