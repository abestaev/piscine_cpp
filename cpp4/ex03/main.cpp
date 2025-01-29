#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    std::cout << "=== Creating MateriaSource ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "=== Creating ane and shrek ===" << std::endl;
    ICharacter* ane = new Character("ane");
    ICharacter* shrek = new Character("shrek");

    std::cout << "=== Creating and equiping ane ===" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    ane->equip(tmp);
    tmp = src->createMateria("cure");
    ane->equip(tmp);

    std::cout << "=== Testing inventory full ===" << std::endl;
    ane->equip(src->createMateria("ice"));
    ane->equip(src->createMateria("cure"));
    ane->equip(src->createMateria("ice")); // Should not equip

    std::cout << "=== Using ice and cure ===" << std::endl;
    ane->use(0, *shrek);
    ane->use(1, *shrek);

    std::cout << "=== Test wrong slot ===" << std::endl;
    ane->use(4, *shrek); // Should not use

    std::cout << "=== Unequiping ice ===" << std::endl;
    ane->unequip(0);
    ane->use(0, *shrek); // Should not use



    delete shrek;
    delete ane;
    delete src;
    return 0;
}

// Should output:
// $> clang++ -W -Wall -Werror *.cpp
// $> ./a.out | cat -e
// * shoots an ice bolt at shrek *$
// * heals shrek' wounds *$