
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap player1("Garen");
    DiamondTrap player2("Darius");
    DiamondTrap player3;

    player1.whoAmI();
    player2.whoAmI();
    player3.whoAmI();
    player2.attack("Garen");
    player1.attack("Darius");
    player3.guardGate();
    player1.takeDamage(5);
    player2.beRepaired(5);
    player1.takeDamage(15);
    player2.beRepaired(15);
    std::cout << "\n";
    for (int i = 0; i < 10; i++) {
        player3.attack("Darius");
    }
    std::cout << "\n";
    player3.highFivesGuys();
    std::cout << "\n";
    return 0;
}