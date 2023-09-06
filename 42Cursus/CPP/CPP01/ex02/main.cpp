
#include <iostream>
#include <string>


int	main() {
	std::string string =  "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "myString : \t" << &string << std::endl;
	std::cout << "stringPTR : \t" << stringPTR << std::endl;
	std::cout << "stringREF : \t" << &stringREF << std::endl;

	std::cout << "myString : \t" << string << std::endl;
	std::cout << "stringPTR :\t" << *stringPTR << std::endl;
	std::cout << "stringREF : \t" << stringREF << std::endl;
}
