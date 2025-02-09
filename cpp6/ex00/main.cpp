#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./convert [value]" << std::endl;
        return 1;
    }

    ScalarConverter sc(av[1]);
    sc.convert();
    return 0;
}