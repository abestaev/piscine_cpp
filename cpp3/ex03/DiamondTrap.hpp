#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(std::string const &name);
        DiamondTrap(DiamondTrap const &other);

        DiamondTrap &operator=(DiamondTrap const &other);

        ~DiamondTrap();

        void attack(std::string const &target);
        void whoAmI();
};

#endif