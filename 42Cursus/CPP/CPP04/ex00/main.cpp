#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal animal;
	animal.makeSound();

	std::cout << std::endl;

	Cat cat;
	cat.makeSound();


	std::cout << "\n-----Subject Tests------\n" << std::endl;


	const Animal* meta = new Animal();
	const Animal* animalDog = new Dog();
	const Animal* animalCat = new Cat();
	std::cout << animalDog->getType() << " " << std::endl;
	std::cout << animalCat->getType() << " " << std::endl;
	animalCat->makeSound(); // will output the cat sound!
	animalDog->makeSound();
	meta->makeSound();
	delete meta;
	delete animalDog;
	delete animalCat;


	std::cout << "\n-----WrongCat Tests------\n" << std::endl;


	const WrongAnimal* wrongAnimalCat = new WrongCat();
	std::cout << wrongAnimalCat->getType() << " " << std::endl;
	wrongAnimalCat->makeSound(); // will output the wrongAnimal sound!
	delete wrongAnimalCat;

	std::cout << "\n-----Destructor Time------\n" << std::endl;
}
