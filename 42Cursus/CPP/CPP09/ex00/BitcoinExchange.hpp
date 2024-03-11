#ifndef INPUT_FILE_PARSER
# define INPUT_FILE_PARSER

# include <string>
#include <map>


class BitcoinExchange
{
	public:
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);

		BitcoinExchange(std::string filePath);

		std::map<std::string, float> getRates() const;

		void	display(int stream);

		// Exceptions
		class NoSpaceLeftException : public  std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return "No space left in span";
			}
		};

	private:
		BitcoinExchange();
		std::map<std::string, float> _rates;
};

#endif // INPUT_FILE_PARSER
