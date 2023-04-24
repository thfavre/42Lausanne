# include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
}

Zombie::~Zombie( void ) {
	std::cout << _name << ": died (again)" << std::endl;

}

void	Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}


