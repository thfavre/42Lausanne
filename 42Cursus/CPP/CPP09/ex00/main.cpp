#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Use : ./head input_file" << std::endl;
		return (1);
	}
	BitcoinExchange btcE = BitcoinExchange(argv[1]);

	btcE.display();

}
