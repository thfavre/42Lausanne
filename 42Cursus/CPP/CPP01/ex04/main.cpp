#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


std::string	readFile(std::ifstream& file) {
	std::string		content;
	std::string		line;

	while (std::getline(file, line))
	{
		// std::cout << line  << std::endl;
		content += line + '\n';
	}
	return (content);
}

std::string	replace(std::string str, std::string s1, std::string s2) {
	std::string	new_string;
	size_t		pos;

	pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{

		// new_string += str.substr(0, pos);
		// new_string += s2;
		// str.erase(0, pos + s1.length());
		// std::cout << "str : " << str << std::endl;
		// std::cout << "pos :"<< pos << std::endl;
		// std::cout << "new :"<< new_string << std::endl << std::endl << std::endl;
	}
	return (new_string);
}

int	main(int argc, char **argv) {
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		infileContent;

	if (argc != 4)
	{
		std::cout << "Wrong number of argument !" << std::endl;
		std::cout << "Usage:" << " ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "Unable to open the file: " << argv[1] << std::endl;
		return (1);
	}

	outfile.open(((std::string)argv[1] + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "Unable to open the file: " << argv[1] << ".replace" << std::endl;
		return (1);
	}
	infileContent = readFile(infile);

	outfile << replace(infileContent, argv[2], argv[3]);
}
