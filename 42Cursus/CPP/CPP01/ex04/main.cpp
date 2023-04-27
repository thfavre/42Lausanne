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

std::string myReplace(std::string str, std::string s1, std::string s2) {
	std::string	new_string;
	size_t		pos;

	pos = 0;
	while ((pos = str.find(s1)) != std::string::npos)
	{
		new_string += str.substr(0, pos);
		new_string += s2;
		str.erase(0, pos + s1.length());
	}
	return (new_string + str);
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
	// open files
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "Unable to open the file: " << argv[1] << std::endl;
		return (1);
	}
	outfile.open((std::string)argv[1] + (std::string)".replace");
	if (outfile.fail())
	{
		std::cout << "Unable to open the file: " << argv[1] << ".replace" << std::endl;
		return (1);
	}
	// read file and replace s1 by s2
	infileContent = readFile(infile);
	outfile << myReplace(infileContent, argv[2], argv[3]);
}
