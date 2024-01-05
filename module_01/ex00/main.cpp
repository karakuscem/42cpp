#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = new Zombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stack Zombie");
    return (0);
}