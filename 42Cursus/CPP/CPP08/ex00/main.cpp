
#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> v1;
	v1.reserve( 3 );

	v1.push_back( 1 );
	v1.push_back( 2 );
	v1.push_back( 3 );

	easyfind(v1, 3);
	easyfind(v1, 4);


	std::list<int> l1;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);

	easyfind(l1, 1);
	easyfind(l1, 4);

}
