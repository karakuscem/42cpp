#include "Zombie.hpp"

int main()
{
    Zombie* horde = zombieHorde(5, "Withers");

    std::cout << "Initialize..." << std::endl;
    for (int i = 0; i < 5; i++)
        horde[i].announce();

    std::cout << "Delete..." << std::endl;
    delete[] horde;
    return (0);
}