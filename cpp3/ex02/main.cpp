#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap user1("Jesus");
    ScavTrap user2;
    FragTrap user3("Chancla");

    user1.attack("Risitas");
    user2.attack("Jesus");
    user2.guardGate();
    user2.takeDamage(5);
    user2.beRepaired(5);
    user2.takeDamage(15);
    user2.beRepaired(15);
    std::cout << "\n";
    for (int i = 0; i < 10; i++) {
        user1.attack("Risitas");
    }
    std::cout << "\n";
    user3.highFivesGuys();
    user3.attack("Risitas");
    std::cout << "\n";
    return 0;
}