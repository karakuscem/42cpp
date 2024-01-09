#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
}

HumanB::~HumanB() {
    
}

void HumanB::attack() {
    if (this->weapon)
        std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

