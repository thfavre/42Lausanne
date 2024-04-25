#include "ScalarConverter.hpp"
#include <cstring>
#include <climits>
#include <cfloat>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
};

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};

Type getType(std::string str)
{
	if (str.length() == 1 && std::isalpha(str[0]))
		return CHAR;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return FLOAT;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return DOUBLE;

	// skips the sign
	size_t i = 0;
	Type type = INT;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length())
	{
		if (std::isdigit(str[i])) {

		} else if (str[i] == '.')
			type = DOUBLE;
		else if (type == DOUBLE && str[i] == 'f')
			type = FLOAT;
		else
			return ERROR;
		i++;
	}
	return i == str.length() ? type : ERROR;
}

void	printSpecial(std::string str)
{
	std::cout << "Char : impossible" << std::endl;
	std::cout << "Int : impossible" << std::endl;
	std::cout << "Double : " << str << std::endl;
	std::cout << "Float : " << str << "f" << std::endl;
}


void	ScalarConverter::convert(std::string str)
{

	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		// remove the 'f' at the end
		str.pop_back();
		printSpecial(str);
		return;
	}
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		printSpecial(str);
		return;
	}

	Type type = getType(str);
	if (type == ERROR)
	{
		std::cout << "Error: invalid input" << std::endl;
		return;
	}
	if (type == CHAR)
	{
		char c = str[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else if (type == INT)
	{
		int i = std::atoi(str.c_str());
		std::cout << "char: ";
		if (i < 32 || i > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else if (type == FLOAT)
	{
		float f = std::atof(str.c_str());
		std::cout << "char: ";
		if (f < 32 || f > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: ";
		if (f < INT_MIN || f > INT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	else if (type == DOUBLE)
	{
		double d = std::stod(str);
		std::cout << "char: ";
		if (d < 32 || d > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: ";
		if (d < INT_MIN || d > INT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
		std::cout << "float: ";
		if (d < -FLT_MAX || d > FLT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}

}
