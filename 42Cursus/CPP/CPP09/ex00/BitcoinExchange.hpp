#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	public :

		BitcoinExchange(const std::string file);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &src);

		std::map<std::string, double> getData() const;

		bool isNumeric(const std::string& str, int mode) const;
		int checkNumber(double number) const;
		int checkDate(std::string date, int mode) const;
		double exchange(std::string date, double value) const;
		std::string findRightDate(const std::string &date) const;
		void printData() const;

	private :
		BitcoinExchange(void);
		std::map<std::string, double> _data;  // to store .csv

};

#endif
