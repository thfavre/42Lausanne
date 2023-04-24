#include "Zombie.hpp"

int main() {
	int	hordeSize;

	hordeSize = 10;
	Zombie *horde = zombieHorde(hordeSize, "Thoum");
	if (!horde)
		return (1);
	for (int i=0; i<hordeSize; i++) {
		horde[i].announce();
	}

	delete [] horde;

}
