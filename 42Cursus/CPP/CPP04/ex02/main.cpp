#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n-----Construction Time!------\n" << std::endl;

	const Animal* dogAnimal = new Dog();
	const Cat* cat = new Cat();
	// const Animal* animal = new Animal(); // NOT POSSIBLE (Animal is a pure virtual class (because makeSound is a pure virtual function)))

	std::cout << "\n-----Types:------\n" << std::endl;

	std::cout << dogAnimal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << "\n-----Sounds :------\n" << std::endl;

	dogAnimal->makeSound();
	cat->makeSound();

	std::cout << "\n-----Destruction Time!------\n" << std::endl;

	delete dogAnimal;
	delete cat;

}
