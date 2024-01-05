#include <iostream>
#include <string>
#include "iter.hpp"


void println(std::string &word)
{
	std::cout << word << std::endl;
}


void addOne(int &nb)
{
	nb++;
}


int main()
{
	std::string colour[4] = { "Blue", "Red", "Orange", "Yellow" };
	iter(colour, 4, println);

	int nbs[2] = {1, 2};
	iter(nbs, 2, addOne);
	std::cout << nbs[0] << " " << nbs[1] << std::endl;
}
