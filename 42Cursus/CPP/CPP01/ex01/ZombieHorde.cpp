#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie* horde = new Zombie[N];
	if (!horde)
		return (NULL);
	for (int i = 0; i < N; i++) {
		horde[i] = Zombie(name);
	}
	return horde;
}
