#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

# define ANIMALS_NBR 4
int main()
{
	Animal	*animals[ANIMALS_NBR];

	std::cout << "\n-----Construction Time!------\n" << std::endl;

	for (int i = 0; i < ANIMALS_NBR; i++)
	{
		if (i < ANIMALS_NBR / 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << "\n-----Make Sounds!------\n" << std::endl;
	for (int i = 0; i < ANIMALS_NBR; i++)
	{
		std::cout << "Type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	std::cout << "\n-----Destruction Time!------\n" << std::endl;
	for (int i = 0; i < ANIMALS_NBR; i++)
		delete animals[i];

}
