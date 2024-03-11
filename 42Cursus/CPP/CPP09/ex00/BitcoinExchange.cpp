#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
// #include <sstream>
// #include <cstdlib>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange()
{
	// ! TODO clean allocations
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}


BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_rates = other.getRates();
	}
	return (*this);
}


BitcoinExchange::BitcoinExchange(std::string filePath)
{
	std::ifstream input(filePath);
	getline( input, NULL );
	for(std::string line; getline( input, line ); )
	{
		std::cout << line << std::endl;
	}
}

// getter+
std::map<std::string, float> BitcoinExchange::getRates() const { return _rates;}

