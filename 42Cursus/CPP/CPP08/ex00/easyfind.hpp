#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
#include <iostream>



template<typename T>
void easyfind(T &intContainer, int item)
{
	if (std::find(intContainer.begin(), intContainer.end(), item) != intContainer.end())
		std::cout << "element " << item << " found in container." << std::endl;
	else
		std::cout << "element " << item << " NOT found in container." << std::endl;
}


#endif // EASYFIND_HPP
