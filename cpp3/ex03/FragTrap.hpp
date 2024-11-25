#ifndef FRAPTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string const &name);
        FragTrap(FragTrap const &other);

        FragTrap &operator=(FragTrap const &other);

        ~FragTrap();

        void highFivesGuys(void);
};

#endif