#include "Zombie.hpp"

int main(void)
{
	Zombie* heapZombie = newZombie("Heap Zombie");
	randomChump("Stack Zombie");
	heapZombie->announce();
	delete heapZombie;
	return (0);
}
