#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
	public:
		static void	convert(std::string str);

	private:
		ScalarConverter();
		~ScalarConverter();
};

#endif
