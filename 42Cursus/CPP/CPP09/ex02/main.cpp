#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 2)
	{
		std::cerr << "\033[1;31mError - please pass a positive integer sequence as argument" << std::endl;
		return (1);
	}
	try
	{
		std::list<int>		unsortedList;
		std::deque<int>		unsortedDeque;
		for (int i = 1; i < ac; i++)
		{
			long int	value;
			char		*endptr;
			value = std::strtol(av[i], &endptr, 10);
			if (*endptr != '\0')
				throw std::invalid_argument("\033[1;31mError - Format of an argument is incorrect. Please pass only a positive integer sequence");
			if (value < 0 || value > INT_MAX)
				throw std::invalid_argument("\033[1;31mError - The value of an argument is not within the range of a positive int");
			int	int_value = static_cast<int>(value);
			unsortedList.push_back(int_value);
			unsortedDeque.push_back(int_value);
		}
		PmergeMe(unsortedList, unsortedDeque);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
