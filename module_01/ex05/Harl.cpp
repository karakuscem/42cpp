#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::debug() {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {

    std::unordered_map<std::string, void (Harl::*)(void)> map;
    map.insert(std::make_pair("DEBUG", &Harl::debug));
    map.insert(std::make_pair("INFO", &Harl::info));
    map.insert(std::make_pair("WARNING", &Harl::warning));
    map.insert(std::make_pair("ERROR", &Harl::error));

    if (map.find(level) != map.end())
        (this->*map[level])();
    else
        std::cout << "Invalid level" << std::endl;
}