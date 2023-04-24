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

std::string replace(std::string str, std::string s1, std::string s2) {
	std::string	new_string;
	size_t		pos;

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

	outfile.open((std::string)argv[1] + (std::string)".replace");
	// check error
	infileContent = readFile(infile);

	outfile << replace(infileContent, argv[2], argv[3]);
}
