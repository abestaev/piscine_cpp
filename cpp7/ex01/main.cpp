#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T x) {
    std::cout << x;
}

template <typename T>
void increment(T &x) {
    x++;
}

int main() {

    //test avec int
    int tab[] = {1, 2 , 3, 4, 5};
    unsigned long size = sizeof(tab) / sizeof(tab[0]);
    iter(tab, size, print);
    std::cout << std::endl;
    iter(tab, size, increment);
    iter(tab, size, print);

    //test avec une chaine de caractere
    std::cout << "\n" << std::endl;
    char str[] = "hello";
    size = sizeof(str) / sizeof(str[0]) - 1;
    iter(str, size, print);
    std::cout << std::endl;
    iter(str, size, increment);
    iter(str, size, print);

    return 0;
}