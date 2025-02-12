#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

//dynamic cast usage: vérifier le type d'un objet
//converti un pointeur de base en pointeur de derive uniquement 
//si la conversion est valide
//retourne null si non valide

Base    *generate(void){
    int i = std::rand() % 3;

    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p){
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch(const std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch(const std::exception &e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main()
{
    std::srand(std::time(0));

    Base *base = generate();
    std::cout << "identify via pointer:   ";
    identify(base);
    std::cout << "identify via reference: ";
    identify(*base);

    delete base;
    return 0;
}