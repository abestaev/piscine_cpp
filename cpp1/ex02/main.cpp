#include <iostream>
#define OE "\033[30;47m"
#define FIN "\033[0m"

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* brainPtr = &brain;
    std::string& brainRef = brain;

    std::cout << "String:     " OE << &brain << FIN << std::endl;
    std::cout << "Pointer:    " OE << brainPtr << FIN << std::endl;
    std::cout << "Reference:  " OE << &brainRef << FIN << std::endl;

    std::cout << "String:     " << brain << std::endl;
    std::cout << "Pointer:    " << *brainPtr << std::endl;
    std::cout << "Reference:  " << brainRef << std::endl;
    return (0);
}