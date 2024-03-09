#include "BitcoinExchange.hpp"


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
	//TODO
}


BitcoinExchange::BitcoinExchange(std::string filePath)
{

}

