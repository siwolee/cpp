#include "Zombie.hpp"

int main()
{
	Zombie	a = Zombie("oldie");
	Zombie* ptr = NULL;

	a.announce();
	ptr = newZombie("newbie");
	(*ptr).announce();
}