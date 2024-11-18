#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA Joseph("Joseph", club);
        Joseph.attack();
        club.setType("some other type of club");
        Joseph.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB Bastien("Bastien");
        Bastien.attack();
        Bastien.setWeapon(club);
        Bastien.attack();
        club.setType("some other type of club");
        Bastien.attack();
    }
    return 0;
}
