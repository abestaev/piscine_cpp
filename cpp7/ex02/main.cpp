#include "Array.hpp"

int main()
{   
    try {
        std::cout << "\033[1;3m[Empty Array]\033[0m" << std::endl;
        Array<int> empty_array;
        std::cout << "Size: " << empty_array.size() << std::endl;
        std::cout << empty_array[0] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    try {
        std::cout << "\033[1;3m\n[Array of size 5]\033[0m" << std::endl;
        Array<int> array(5);
        std::cout << "Size: " << array.size() << std::endl;
        std::cout << "array:      ";
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << "[" << array[i] << "]";
        std::cout << std::endl;
        
        std::cout << "\033[1;3m\n[Test de copie]\033[0m" << std::endl;
        Array<int> array_copy = array;
        std::cout << "Size: " << array_copy.size() << std::endl;
        std::cout << "array_copy: ";
        for (unsigned int i = 0; i < array_copy.size(); i++)
        {
            array_copy[i] = i;
            std::cout << "[" << array_copy[i] << "]";
        }
        std::cout << std::endl;

        std::cout << "\033[1;3m\n[Test de modif array 1]\033[0m" << std::endl;
        array[0] = 42;
        std::cout << "array:      ";
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << "[" << array[i] << "]";
        std::cout << std::endl;
        std::cout << "array_copy: ";
        for (unsigned int i = 0; i < array_copy.size(); i++)
            std::cout << "[" << array_copy[i] << "]";
        std::cout << std::endl;

        std::cout << "\033[1;3m\n[Test out of bounds]\033[0m" << std::endl;
        std::cout << array_copy[7] << std::endl;

        std::cout << "Fin des tests" << std::endl;


    } catch (std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}