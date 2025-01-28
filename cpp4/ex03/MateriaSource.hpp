#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_inventory[4];
        int _count;

    public:
        MateriaSource();
        MateriaSource(MateriaSource const & src);
        MateriaSource &operator=(MateriaSource const & src);
        virtual ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif