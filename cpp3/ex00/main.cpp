#include "ClapTrap.hpp"

int main() {
    ClapTrap user1("Jesus");
    ClapTrap user2;

    user1.attack("Risitas");
    user2.takeDamage(5);
    user2.beRepaired(5);
    user2.takeDamage(15);
    user2.beRepaired(15);
    std::cout << "\n";
    for (int i = 0; i < 10; i++) {
        user1.attack("Risitas");
    }
    std::cout << "\n";
    return 0;
}