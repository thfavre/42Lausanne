#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

int main()
{
	Animal animal;
	animal.makeSound();

	std::cout << std::endl;

	Cat cat;
	cat.makeSound();

	std::cout << "\n-----Subject Tests------\n" << std::endl;


	const Animal* meta = new Animal();
	// const Animal* animalDog = new Dog();
	const Animal* animalCat = new Cat();
	// std::cout << animalDog->getType() << " " << std::endl;
	std::cout << animalCat->getType() << " " << std::endl;
	animalCat->makeSound(); //will output the cat sound!
	// animalDog->makeSound();
	meta->makeSound();

		std::cout << "\n-----Destructor Time------\n" << std::endl;


}
