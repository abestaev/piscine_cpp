#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("jsommet");
    zombie->announce();
    randomChump("bazaluga");
    delete zombie;
    return (0);
}