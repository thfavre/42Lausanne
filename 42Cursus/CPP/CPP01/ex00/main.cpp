#include "Zombie.hpp"
#include <iostream>


int main() {
	// on Heap
	Zombie *charles = newZombie("Charles");
	charles->announce();
	delete charles;
	// on Stack
	randomChump("Pierre");
}
