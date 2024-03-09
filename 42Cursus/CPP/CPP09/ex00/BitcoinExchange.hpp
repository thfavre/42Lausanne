#ifndef INPUT_FILE_PARSER
# define INPUT_FILE_PARSER

# include <string>

class BitcoinExchange
{
	public:
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);

		BitcoinExchange(std::string filePath);

		void	display(int stream);

	private:
		BitcoinExchange();
};

#endif // INPUT_FILE_PARSER
